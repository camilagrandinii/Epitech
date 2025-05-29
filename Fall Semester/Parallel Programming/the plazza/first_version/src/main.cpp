/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <filesystem>
#include <sys/types.h>

#include "ICP.hpp"
#include "Plazza.hpp"
#include "Kitchen.hpp"
#include "Reception.hpp"
#include "EventsLogging.hpp"

static const char *help = "USAGE\n\t./plazza cT cPK dT\n\nDESCRIPTION"\
"\n\tcT\tMultiplier for the cooking time of the pizzas."\
"\n\tcPK\tNumber of cooks per kitchen."\
"\n\tdT\ttime in milliseconds, used by the kitchen stock to replace ingredients.";

static bool isStrInt(const std::string &str)
{
    std::string::const_iterator it = str.begin();

    while (it != str.end() && std::isdigit(*it)) ++it;
    return (!str.empty() && it == str.end());
}

static void error_handling(Options &opt, int ac, char **av)
{
    if (ac == 1 && strcmp(av[0], "-h")) {
        std::cout << help << std::endl;
        exit(0);
    }
    if (ac != 3) {
        exit(84);
    }
    for (int i = 0; av[i]; ++i) {
        std::string s(av[i]);
        if (!isStrInt(s)) {
            std::cout << "\"" << s << "\"" << " Is not a Integer" << std::endl;
            exit(84);
        }
    }
    opt.multiplierCooking = atoi(av[0]);
    opt.cooksNumber = atoi(av[1]);
    opt.regenerationTime = atoi(av[2]);
}

static bool isValidIngredient(const std::string &ingredient)
{
    for (int i = 0; IngredientsStrings[i] != nullptr; ++i) {
        if (ingredient == IngredientsStrings[i]) {
            return (true);
        }
    }
    return (false);
}

static std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return (tokens);
}

static std::shared_ptr<std::vector<std::unique_ptr<Plazza::IPizza>>> getPizzaListFromFile(void)
{
    static const std::filesystem::path path = "conf/pizza.conf";
    std::ifstream file(path);

    if (!file.is_open()) {
        std::vector<Ingredients> ingredients;
        auto tmpPizzaList = std::make_shared<std::vector<std::unique_ptr<Plazza::IPizza>>>();

        ingredients = { Dough, Tomato, Gruyere };
        tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("margarita", ingredients, 1));

        ingredients = { Dough, Tomato, Gruyere, Ham, Mushrooms };
        tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("regina", ingredients, 2));

        ingredients = { Dough, Tomato, Gruyere, Steak };
        tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("americana", ingredients, 2));

        ingredients = { Dough, Tomato, Eggplant, GoatCheese, ChiefLove };
        tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("fantasia", ingredients, 4));

        return (tmpPizzaList);
    } else {
        std::string line;
        auto tmpPizzaList = std::make_shared<std::vector<std::unique_ptr<Plazza::IPizza>>>();

        while (getline(file, line)) {
            auto parts = splitString(line, ',');
            if (parts.size() != 3) {
                throw std::logic_error("Invalid configuration file");
            }

            std::string name = parts[0];
            int cookingTime = std::stoi(parts[1]);
            auto ingredientParts = splitString(parts[2], '-');

            std::vector<Ingredients> ingredients;
            for (const auto &ingredientName : ingredientParts) {
                if (!isValidIngredient(ingredientName)) {
                    throw std::logic_error("Invalid pizza");
                    ingredients.clear();
                    break;
                }
                ingredients.push_back(static_cast<Ingredients>(std::distance(IngredientsStrings, std::find(IngredientsStrings, IngredientsStrings + sizeof(IngredientsStrings) / sizeof(IngredientsStrings[0]), ingredientName))));
            }
            if (!ingredients.empty()) {
                tmpPizzaList->push_back(std::make_unique<Plazza::APizza>(name, ingredients, cookingTime));
            }
        }
        return (tmpPizzaList);
    }
    return (nullptr);
}

int main(int ac, char **av)
{
    Options opt;
    Plazza::PlazzaLogger logger;

    const std::shared_ptr<std::vector<std::unique_ptr<Plazza::IPizza>>> pizzaList = getPizzaListFromFile();
    error_handling(opt, ac - 1, av + 1);

    if (pizzaList == nullptr) {
        return (84);
    }

    Plazza::Reception reception(opt, pizzaList);
    reception.Run();
    return (0);
}

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <cmath>
#include <fstream>
#include "Reception.hpp"

static int isValidIngredient(const std::string &ingredient)
{
    for (int i = 0; PizzaIngredientsStr[i]; ++i) {
        if (ingredient == PizzaIngredientsStr[i]) {
            return (i);
        }
    }
    return (-1);
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

std::vector<Plazza::APizza> parseConfigurationFile(std::filesystem::path pathToConfFIle)
{
    std::ifstream file(pathToConfFIle);
    std::string line;
    std::vector<Plazza::APizza> pizzaList;

    while (getline(file, line)) {
        auto parts = splitString(line, ',');
        if (parts.size() != 3) {
            throw std::logic_error("Pizza in conf file are like PIZZA,SIZE,INGREDIENTS");
        }

        std::string name = parts[0];
        int cookingTime = std::stoi(parts[1]);
        auto ingredientParts = splitString(parts[2], '-');

        std::vector<Ingredients> ingredients;
        for (const auto &ingredientName : ingredientParts) {
            int i = isValidIngredient(ingredientName);
            if (i == -1) {
                throw std::logic_error("Invalid Ingredient");
            }
            ingredients.emplace_back(static_cast<Ingredients>(pow(2, i)));
        }
        if (!ingredients.empty()) {
            pizzaList.emplace_back(name, ingredients, cookingTime);
        }
    }
    return (pizzaList);
}
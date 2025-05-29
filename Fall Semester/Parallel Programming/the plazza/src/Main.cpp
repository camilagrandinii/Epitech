/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <iostream>
#include "Macro.hpp"
#include "Reception.hpp"

int main(int ac, char **av)
{
    Configuration configuration;

    if (ArgsHandling(ac - 1, av + 1, configuration) == FAIL) {
        return (FAIL);
    }

    PIZZALIST pizzaList;
    if (configuration.pathToConfFile != "") {
        try {
            pizzaList = parseConfigurationFile(configuration.pathToConfFile);
        } catch(const std::exception& e) {
            std::cout << "Bad configuration file" << '\n';
            return (84);
        }
    } else {
        std::vector<Ingredients> ingredients;

        ingredients = { Dough, Tomato, Gruyere };
        pizzaList.emplace_back("margarita", ingredients, 1);

        ingredients = { Dough, Tomato, Gruyere, Ham, Mushrooms };
        pizzaList.emplace_back("regina", ingredients, 2);

        ingredients = { Dough, Tomato, Gruyere, Steak };
        pizzaList.emplace_back("americana", ingredients, 2);

        ingredients = { Dough, Tomato, Eggplant, GoatCheese, ChiefLove };
        pizzaList.emplace_back("fantasia", ingredients, 4);
    }

    Plazza::Reception reception(configuration.option, pizzaList);
    reception.Run();

    return (SUCCESS);
}

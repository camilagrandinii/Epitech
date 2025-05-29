/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef PLAZZA_HPP
    #define PLAZZA_HPP

    #include <filesystem>

struct Option {
    int cookingTime;
    int numberOfCooks;
    int ingredientsRestockDelay;
};

struct Configuration {
    Option option;
    std::filesystem::path pathToConfFile = "";
};

int ArgsHandling(int ac, char **av, Configuration &configuration);

#endif /* PLAZZA_HPP */

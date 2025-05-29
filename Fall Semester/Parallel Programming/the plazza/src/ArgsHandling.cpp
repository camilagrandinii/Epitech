/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <fstream>
#include <iostream>
#include <filesystem>
#include "Macro.hpp"
#include "Plazza.hpp"

inline static char const * const help = \
"USAGE:\n\t"\
"./plazza c k t [-conf=PATH]\n\n"\
"DESCRIPTION:\n\t"\
"c\tmultiplier for the cooking time of the pizzas.\n\t"\
"k\tcooks per kitchen.\n\t"\
"t\ttime in milliseconds o replace ingredients.\n\t"\
"[-conf=PATH]\n\t\t-conf flag to link a configuration file for pizza\n\t\t"\
"PATH is path (relative or absolute) to the configuration file";

#include <iostream>
#include <string>

static std::string splitString(const std::string &flag)
{
    size_t pos = flag.find("=");
    std::string path;

    if (pos != std::string::npos) {
        path = flag.substr(pos + 1);
    } else {
        path = "";
    }
    return (path);
}

static bool CheckIfConfFileExist(std::string pathToConfFile, Configuration &configuration)
{
    pathToConfFile = splitString(pathToConfFile);

    if (pathToConfFile == "") {
        std::cout << "No path given" << std::endl;
        return (false);
    }

    std::filesystem::path pathToFile(pathToConfFile);
    std::ifstream file(pathToFile);

    if (!file) {
        std::cout << "Path: \'" << pathToConfFile << "\' is invalid" << std::endl;
        return (false);
    }
    file.close();
    configuration.pathToConfFile = pathToConfFile;
    return (true);
}

static bool CheckIfArgsAreInt(char **av, Configuration &configuration)
{
    for (int i = 0; i != 3 && av[i]; ++i) {
        try {
            size_t pos;
            int val = std::stoi(av[i], &pos);

            return (true);
        } catch (const std::invalid_argument &) {
            std::cout << "Invalid or negative int" << std::endl;
            return (false);
        } catch (const std::out_of_range &) {
            std::cout << "Too long int" << std::endl;
            return (false);
        }
    }
    configuration.option.cookingTime = std::stoi(av[0]);
    configuration.option.numberOfCooks = std::stoi(av[1]);
    configuration.option.ingredientsRestockDelay = std::stoi(av[2]);
    return (true);
}

int ArgsHandling(int ac, char **av, Configuration &configuration)
{
    if (ac == 1 && av[0] == "-h") {
        std::cout << help << std::endl;
        exit(SUCCESS);
    } else if (ac == 3) {
        if (CheckIfArgsAreInt(av, configuration) == false) {
            std::cout << "Args arent int" << std::endl;
            return (FAIL);
        }
        return (SUCCESS);
    } else if (ac == 4) {
        if (CheckIfArgsAreInt(av, configuration) == false) {
            std::cout << "Args arent int" << std::endl;
            return (FAIL);
        }
        if (CheckIfConfFileExist(av[3], configuration) == false) {
            std::cout << "File dont exist" << std::endl;
            return (FAIL);
        }
        return (SUCCESS);
    }
    return (FAIL);
}

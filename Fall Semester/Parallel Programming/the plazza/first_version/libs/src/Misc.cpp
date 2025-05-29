/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string>
#include <cstring>
#include "Plazza.hpp"

bool isAlphaString(std::string str)
{
    const char *cstr = str.c_str();

    for (int i = 0; cstr[i]; i++) {
        if (isalpha(cstr[i]) == false) {
            return (false);
        }
    }
    return (true);
}

bool isSize(std::string size)
{
    const char *cstr = size.c_str();

    for (int i = 0; PizzaSizeStrings[i]; i++) {
        if (strcmp(PizzaSizeStrings[i], cstr) == 0) {
            return (true);
        }
    }
    return (false);
}

bool isNumber(std::string number)
{
    const char *cstr = number.c_str();

    if (strlen(cstr) < 2 && strlen(cstr) > 3) {
        return (false);
    }
    if (cstr[0] != 'x') {
        return (false);
    }
    if (cstr[1] < '0' && cstr[1] > '9') {
        return (false);
    }
    if (cstr[2] != 0) {
        if (cstr[2] < '0' && cstr[2] > '9') {
            return (false);
        }
    }
    return (true);
}

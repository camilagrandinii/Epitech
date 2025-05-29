/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Reception.hpp"

static bool isAlphaString(const std::string &str)
{
    const char *cstr = str.c_str();

    for (int i = 0; cstr[i]; i++) {
        if (isalpha(cstr[i]) == false) {
            return (false);
        }
    }
    return (true);
}

static bool isSize(const std::string &size)
{
    const char *cstr = size.c_str();

    for (int i = 0; PizzaSizeStr[i]; i++) {
        if (strcmp(PizzaSizeStr[i], cstr) == 0) {
            return (true);
        }
    }
    return (false);
}

static bool isNumber(const std::string &number)
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

static bool isType(const std::string &type, PIZZALIST &pizzaList)
{
    for (const auto &i: pizzaList) {
        if (i.getName() == type) {
            return (true);
        }
    }
    return (false);
}

static PizzaSize convertStringToPizzaSize(const std::string &size)
{
    if (size == "S") {
        return (S);
    }  else if (size == "M") {
        return (M);
    }  else if (size == "L") {
        return (L);
    }  else if (size == "XL") {
        return (XL);
    }  else if (size == "XXL") {
        return (XXL);
    }
    return (S);
}

static short convertStringToNumberOfPizza(const std::string &number)
{
    return ((short)std::stoi(number.substr(1)));
}

Plazza::APizza getPizza(PIZZALIST pizzaList, const std::string &pizzaName)
{
    for (auto i: pizzaList) {
        if (i.getName() == pizzaName) {
            return (i);
        }
    }
    return (pizzaList[0]);
}

bool Plazza::Reception::parseInput(const std::string &str)
{
    std::stringstream userInput(str);
    std::string token;
    std::vector<std::string> ordersString;

    static const char differentPizzaToken = ';';
    while (getline(userInput, token, differentPizzaToken)) {
        ordersString.push_back(token); 
    }
    if (ordersString.size() == 0) {
        return (false);
    }

    static const char splitElementToken = ' ';
    std::vector<PIZZAORDER> order;
    for (auto &i: ordersString) {
        std::vector<std::string> stringVectorOrder;
        std::stringstream splitedUserInput(i);

        while (getline(splitedUserInput, token, splitElementToken)) {
            if (token.length() > 0) {
                stringVectorOrder.push_back(token);
            }
        }

        if (stringVectorOrder.size() != 3) {
            std::cout << "Not enough args: \'" << token << "\'" << std::endl;
            return (false);
        }

        /* TESTING IF PIZZA NAME IS VALID */
        std::string strPizzaName(stringVectorOrder[0]);
        if (isAlphaString(strPizzaName) != true) {
            std::cout << "Non Alpha Pizza Name" << strPizzaName << std::endl;
            return (false);
        }
        if (isType(strPizzaName, this->pizzaList) != true) {
            std::cout << "Incorrect Pizza Name: " << strPizzaName << std::endl;
            return (false);
        }
        /**********************************/

        /* TESTING IF PIZZA SIZE IS VALID */
        std::string strPizzaSize(stringVectorOrder[1]);
        if (isAlphaString(strPizzaSize) != true) {
            std::cout << "Non Alpha Pizza Size" << strPizzaSize << std::endl;
            return (false);
        }
        if (isSize(strPizzaSize) != true) {
            std::cout << "Incorrect Pizza Size: " << strPizzaSize << std::endl;
            return (false);
        }
        /**********************************/

        /* TESTING IF PIZZA NUMBER IS VALID */
        std::string strPizzaNumber(stringVectorOrder[2]);
        if (isNumber(strPizzaNumber) != true) {
            std::cout << "Invalid number asked: " << strPizzaNumber << std::endl;
            return (false);
        }
        /************************************/

        Plazza::APizza tmp = getPizza(this->pizzaList, strPizzaName);

        for (short i = 0; i != convertStringToNumberOfPizza(strPizzaNumber); i++) {
            order.emplace_back(QuadrUplet<Plazza::APizza, PizzaSize, bool, bool>(tmp, convertStringToPizzaSize(strPizzaSize), false, false), order.size());
        }
    }
    this->orders.emplace_back(order, this->orderNumber++);
    return (true);
}

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "APizza.hpp"

Plazza::APizza::APizza(std::string name, std::vector<Ingredients> ingredients, int cookingTime)
    : name(name), ingredients(ingredients), cookingTime(cookingTime) {}

Plazza::APizza::APizza(const APizza &other)
{
    this->name = other.name;
    this->ingredients = other.ingredients;
    this->cookingTime = other.cookingTime;

}

int Plazza::APizza::getCookingTime(void) const noexcept
{
    return (this->cookingTime);
}

std::string Plazza::APizza::getName(void) const noexcept
{
    return (this->name);
}

std::vector<Ingredients> Plazza::APizza::getIngredients(void) const noexcept
{
    return (this->ingredients);
}

Plazza::APizza &Plazza::APizza::operator=(const Plazza::APizza &other)
{
    this->name = other.name;
    this->ingredients = other.ingredients;
    this->cookingTime = other.cookingTime;

    return (*this);
}

/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::string transformBoolToString(bool b) {
  if (b)
    return "true";
  return "false";
}

std::ostream &operator<<(std::ostream &stream, const IFruit &fruit) {
  stream << "[name: “" << fruit.getName()
         << "“, vitamins: " << fruit.getVitamins()
         << " peeled: " << transformBoolToString(fruit.isPeeled()) << "]";
  return (stream);
}
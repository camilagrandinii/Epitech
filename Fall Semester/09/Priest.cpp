/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Enchanter(name, power)
{
    std::cout << *this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << *this->_name << " finds peace." << std::endl;
}

int Priest::attack()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() < 0) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " doesn’t know how to fight." << std::endl;
    return 0;
}

int Priest::special()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 50) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " casts a fireball." << std::endl;
    this->_power -= 50;
    return 99;
}

void Priest::rest()
{
    this->_power = 100;
    this->_hp = 100;
    std::cout << *this->_name << " prays." << std::endl;
}
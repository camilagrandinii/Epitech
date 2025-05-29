/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power): _name(new std::string(name))
{
    if (power > 100){
        power = 100;
    } else if (power < 0){
        power = 0;
    }
    
    this->_power = power;
    
    std::cout << *this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << *this->_name << " is back to his crops." << std::endl;
}

int Peasant::getPower() const
{
    return this->_power;
}

int Peasant::getHp() const
{
    return this->_hp;
}

const std::string &Peasant::getName() const
{
    return *this->_name;
}

int Peasant::attack()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() <= 9) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " tosses a stone." << std::endl;
    this->_power -= 10;
    return 5;
}

int Peasant::special()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 0) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return ;
    }
    if (this->_power < 0) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return ;
    }
    if (this->_power + 30 > 100)
        this->_power = 100;
    else
        this->_power += 30;
    std::cout << *this->_name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return ;
    }
    this->_hp -= damage;
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        this->_hp = 0;
    } else
        std::cout << *this->_name << " takes " << damage << " damage." << std::endl;
}

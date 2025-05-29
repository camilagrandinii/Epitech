/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power)
    : Peasant(name, power) {
  std::cout << *this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter() {
  std::cout << *this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack() {
  if (this->_hp <= 0) {
    std::cout << *this->_name << " is out of combat." << std::endl;
    return 0;
  }
  if (this->_power < 0) {
    std::cout << *this->_name << " is out of power." << std::endl;
    return 0;
  }
  std::cout << *this->_name << " doesn't know how to fight." << std::endl;
  return 0;
}

int Enchanter::special() {
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

void Enchanter::rest() {
  if (this->_hp <= 0) {
    std::cout << *this->_name << " is out of combat." << std::endl;
    return;
  }
  if (this->_power < 0) {
    std::cout << *this->_name << " is out of power." << std::endl;
    return;
  }
  this->_power = 100;
  std::cout << *this->_name << " meditates." << std::endl;
}

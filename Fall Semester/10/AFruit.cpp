#include "AFruit.hpp"
#include <iostream>

AFruit::~AFruit(){};

std::string AFruit::getName() const { return _name; };
unsigned int AFruit::getVitamins() const {
  if (_peeled) {
    return _vitamins;
  } else {
    return 0;
  }
};
void AFruit::peel() { _peeled = true; };
bool AFruit::isPeeled() const { return _peeled; };
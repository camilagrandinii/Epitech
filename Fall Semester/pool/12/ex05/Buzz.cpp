#include "Buzz.hpp"
#include <iostream>

Buzz::Buzz(const std::string &name, const std::string &filename)
    : Toy(Toy::BUZZ, name, filename) {}

Buzz::~Buzz() {}

void Buzz::speak(const std::string &statement) {
  std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string &statement) {
  std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" senorita"
            << std::endl;
  return true;
}

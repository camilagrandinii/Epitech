/*
** EPITECH PROJECT, 2024
** Pool - Day 12
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture() {}

Toy::Toy(const Toy &copy)
    : _type(copy._type), _name(copy._name), _picture(copy._picture) {}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
    : _type(type), _name(name), _picture(filename) {}

Toy::~Toy() {}

Toy::ToyType Toy::getType() const { return _type; }

std::string Toy::getName() const { return _name; }

void Toy::setName(const std::string &name) { _name = name; }

bool Toy::setAscii(const std::string &filename) {
  if (_picture.getPictureFromFile(filename) == true)
    return true;
  else {
    _error._where = "setAscii";
    _error._what = "bad new illustration";
    _error.type = Toy::Error::ErrorType::PICTURE;
  }
  return false;
}

std::string Toy::getAscii() const { return _picture._data; }

Toy &Toy::operator=(const Toy &copy) {
  _type = copy._type;
  _name = copy._name;
  _picture = copy._picture;
  return *this;
}

void Toy::speak(const std::string &statement) {
  std::cout << _name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(const std::string &statement) {
  (void)(statement);
  _error._where = "speak_es";
  _error._what = "wrong mode";
  _error.type = Toy::Error::ErrorType::SPEAK;
  return false;
}

const Toy::Error &Toy::getLastError() const { return _error; }

std::ostream &operator<<(std::ostream &stream, const Toy &toy) {
  stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
  return stream;
}

Toy &Toy::operator<<(const std::string &filename) {
  _picture._data = filename;
  return *this;
}

Toy::Error::Error() {
  _what = "";
  _where = "";
  type = UNKNOWN;
}

Toy::Error::~Error() {}

const std::string &Toy::Error::what() const { return _what; }

const std::string &Toy::Error::where() const { return _where; }
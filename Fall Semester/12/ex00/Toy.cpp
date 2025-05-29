#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture() {}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
    : _type(type), _name(name), _picture(filename) {}

Toy::~Toy() {}

Toy::ToyType Toy::getType() const { return _type; }

std::string Toy::getName() const { return _name; }

void Toy::setName(const std::string &name) { _name = name; }

bool Toy::setAscii(const std::string &filename) {
  return _picture.getPictureFromFile(filename);
}

std::string Toy::getAscii() const { return _picture._data; }
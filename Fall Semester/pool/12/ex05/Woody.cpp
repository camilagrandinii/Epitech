#include "Woody.hpp"
#include "Toy.hpp"

Woody::Woody(const std::string &name, const std::string &filename)
    : Toy(Toy::WOODY, name, filename) {}

Woody::~Woody() {}

void Woody::speak(const std::string &statement) {
  std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
}

bool Woody::speak_es(const std::string &statement) {
  (void)(statement);
  _error._where = "speak_es";
  _error._where = "wrong mode";
  _error.type = Toy::Error::ErrorType::SPEAK;
  return false;
}

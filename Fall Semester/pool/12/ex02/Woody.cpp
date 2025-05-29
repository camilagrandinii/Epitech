#include "Woody.hpp"
#include "Toy.hpp"

Woody::Woody(const std::string &name, const std::string &filename)
    : Toy(Toy::WOODY, name, filename) {}

Woody::~Woody() {}

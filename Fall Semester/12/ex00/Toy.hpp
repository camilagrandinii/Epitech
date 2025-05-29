/*
** EPITECH PROJECT, 2024
** Pool - Day 12
** File description:
** Toy Header
*/

#ifndef TOY_FILE
#define TOY_FILE

#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <vector>

#include "Picture.hpp"

class Toy
{
public:
    enum ToyType {BASIC_TOY, ALIEN};
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &filename);
    ~Toy();
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &filename);
    std::string getAscii() const;
private:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

#endif

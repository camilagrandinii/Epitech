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

#include "Picture.hpp"

class Toy
{
public:
    enum ToyType {BASIC_TOY, ALIEN, WOODY, BUZZ};
    Toy();
    Toy(const Toy &copy);
    Toy(ToyType type, const std::string &name, const std::string &filename);
    ~Toy();
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &filename);
    std::string getAscii() const;
    virtual void speak(const std::string &statement);
    Toy &operator=(const Toy &copy);
    Toy& operator<<(const std::string &filename);
protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

std::ostream &operator<<(std::ostream &, const Toy&);
std::ostream &operator<<(std::string &, const Toy&);

#endif
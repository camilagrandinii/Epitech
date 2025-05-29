/*
** EPITECH PROJECT, 2024
** Pool - Day 12
** File description:
** Woody Header
*/

#ifndef WOODY_FILE
#define WOODY_FILE

#include <iostream>
#include <fstream>

#include "Toy.hpp"

class Woody : public Toy
{
public:
    Woody(const std::string &name, const std::string &filename = "woody.txt");
    ~Woody();
    void speak(const std::string &statement) override;
};

#endif

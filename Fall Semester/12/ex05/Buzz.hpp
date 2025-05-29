/*
** EPITECH PROJECT, 2024
** Pool - Day 12
** File description:
** Toy Header
*/

#ifndef BUZZ_FILE
#define BUZZ_FILE

#include <iostream>
#include <fstream>

#include "Toy.hpp"

class Buzz : public Toy
{
public:
    Buzz(const std::string &name, const std::string &filename = "buzz.txt");
    ~Buzz();
    void speak(const std::string &statement) override;
    bool speak_es(const std::string &statement) override;
};

#endif

/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Paladin Header
*/

#ifndef PALADIN_FILE
#define PALADIN_FILE

#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : virtual public Knight, virtual public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack();
        int special();
        void rest();
};

#endif 

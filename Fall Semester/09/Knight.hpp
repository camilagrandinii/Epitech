/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Knight Header
*/

#ifndef KNIGHT_FILE
#define KNIGHT_FILE

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        int attack() override;
        int special();
        void rest();
};

#endif

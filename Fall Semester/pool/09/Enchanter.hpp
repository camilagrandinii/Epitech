/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Enchanter Header
*/

#ifndef ENCHANTER_FILE
#define ENCHANTER_FILE

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        int attack() override;
        int special();
        void rest();
};

#endif

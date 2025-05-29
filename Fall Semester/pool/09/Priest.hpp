/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Priest Header
*/

#ifndef PRIEST_FILE
#define PRIEST_FILE

#include "Enchanter.hpp"

class Priest : virtual public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        int attack() override;
        int special();
        void rest();
};

#endif

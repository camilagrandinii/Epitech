/*
** EPITECH PROJECT, 2024
** Pool - Day 09
** File description:
** Peasant Header
*/

#include <string>

#ifndef PEASANT_FILE
#define PEASANT_FILE

#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;

        virtual int attack();
        virtual int special();
        virtual void rest();
        virtual void damage(int damage) final;

    protected:
        std::string *_name;
        int _power;
        int _hp = 100;
};

#endif 

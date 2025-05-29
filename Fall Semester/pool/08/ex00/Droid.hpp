/*
** EPITECH PROJECT, 2024
** Pool - Day 08
** File description:
** Droid Header
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <vector>

#ifndef DROID_FILE
#define DROID_FILE

class Droid
{
private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;

public:
    Droid(std::string serialNumber = "");
    Droid(Droid const &);
    ~Droid();
    Droid &operator=(const Droid &droid);
    bool operator==(const Droid &a) const;
    bool operator!=(const Droid &a) const;
    Droid &operator<<(size_t &add);
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    void setId(std::string ID);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
};

std::ostream &operator<<(std::ostream &flux, const Droid &droid);

#endif
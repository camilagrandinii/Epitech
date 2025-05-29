/*
** EPITECH PROJECT, 2024
** Pool - Day 08
** File description:
** Droid Implementation
*/
#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string serialNumber) : Id(serialNumber), Energy(50), Attack(25),
                                              Toughness(15), Status(new std::string("Standing By")) {
                                                std::cout << "Droid '" << serialNumber << "' Activated" << std::endl;
                                              }

Droid::Droid(Droid const &droid) : Id(droid.getId()), Energy(droid.getEnergy()), Attack(25), Toughness(15), Status(new std::string(*droid.getStatus()))
{
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete this->Status;
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &droid)
{
    this->setEnergy(droid.Energy);
    this->setId(droid.Id);
    this->setStatus(droid.Status);
    return *this;
}

bool Droid::operator==(const Droid &droid) const
{
    if (this->getId() != droid.Id)
        return false;
    if (this->getAttack() != droid.Attack)
        return false;
    if (this->getEnergy() != droid.Energy)
        return false;
    if (*(this->getStatus()) != *(droid.Status))
        return false;
    if (this->getToughness() != droid.Toughness)
        return false;
    return true;
}

bool Droid::operator!=(const Droid &droid) const
{
    if (this->getAttack() != droid.Attack)
        return true;
    if (this->getEnergy() != droid.Energy)
        return true;
    if (this->getId() != droid.Id)
        return true;
    if (*(this->getStatus()) != *(droid.Status))
        return true;
    if (this->getToughness() != droid.Toughness)
        return true;
    return false;
}

Droid &Droid::operator<<(size_t &add)
{
    size_t res;

    if (this->Energy >= 100) {
        this->Energy = 100;
        return (*this);

    } else if (this->Energy + add >= 100) {
        res = 100 - this->Energy;
    } else {
        res = add;
    }

    this->Energy += res;
    add -= res;
    
   return (*this);
}

std::ostream &operator<<(std::ostream &flux, const Droid &droid)
{
    flux << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return flux;
}

std::string Droid::getId() const
{
    return Id;
}

size_t Droid::getEnergy() const
{
    return Energy;
}

size_t Droid::getAttack() const
{
    return Attack;
}

size_t Droid::getToughness() const
{
    return Toughness;
}

std::string *Droid::getStatus() const
{
    return Status;
}

void Droid::setId(std::string ID)
{
    Id = ID;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
    {
        energy = 100;
    } else { 
        Energy = energy;
    }
}

void Droid::setStatus(std::string *status)
{
    Status = status;
}
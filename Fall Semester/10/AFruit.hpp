/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** AFruit Header
*/

#ifndef AFRUIT_FILE
#define AFRUIT_FILE

#include <string>
#include <iostream>

#include "IFruit.hpp"

class AFruit : public IFruit {
  public:
    AFruit() = default;
    virtual ~AFruit();
    virtual std::string getName() const override;
    virtual unsigned int getVitamins() const override;
    virtual bool isPeeled() const override;
    virtual void peel() override;

  protected:
    std::string _name;
    int _vitamins;
    bool _peeled; 
};

#endif

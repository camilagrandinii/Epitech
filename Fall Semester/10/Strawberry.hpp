/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** Strawberry Header
*/

#ifndef STRAWBERRY_FILE
#define STRAWBERRY_FILE

#include "ABerry.hpp"

class Strawberry : public ABerry {
public :
   Strawberry(){
     _name = "strawberry";
     _vitamins = 6;
     _peeled = true;
   };
  ~Strawberry();
};

#endif
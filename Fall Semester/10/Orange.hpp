/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** Orange Header
*/

#ifndef AORANGE_FILE
#define AORANGE_FILE

#include "ACitrus.hpp"

class Orange : public ACitrus {
public :
   Orange(){
     _name = "orange";
     _vitamins = 7;
     _peeled = false;
   }
  ~Orange();
};

#endif
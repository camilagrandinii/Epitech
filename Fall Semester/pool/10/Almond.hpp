/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** Almond Header
*/

#ifndef AAlmond_FILE
#define AAlmond_FILE

#include "ANut.hpp"

class Almond : public ANut {
public :
 Almond(){
     _name = "almond";
     _vitamins = 2;
     _peeled = false;
   };

  ~Almond();
};

#endif
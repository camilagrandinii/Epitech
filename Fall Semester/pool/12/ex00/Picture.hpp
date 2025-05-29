/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** Picture Header
*/

#ifndef PICTURE_FILE
#define PICTURE_FILE

#include <iostream>

class Picture {
  public:
    std::string _data;
    Picture();
    Picture(const std::string &file);
    ~Picture();
    bool getPictureFromFile(const std::string &file);
};

#endif
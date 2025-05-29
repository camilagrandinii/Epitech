/*
** EPITECH PROJECT, 2024
** A Game of Toys
** File description:
** Picture Header File
*/

#ifndef Picture_H
#define Picture_H

#include <iostream>
#include <fstream>

class Picture
{
private:
public:
    Picture();
    Picture(const Picture &copy);
    Picture(const std::string &file);
    ~Picture();
    Picture &operator=(const Picture &copy);
    bool getPictureFromFile(const std::string &file);
    std::string _data;
};

#endif
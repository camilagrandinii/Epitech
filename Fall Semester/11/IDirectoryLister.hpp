/*
** EPITECH PROJECT, 2024
** Pool - Day 11
** File description:
** Directory Lister Header Interface
*/

#include <string>

#ifndef IDIRECTORY_LISTER_FILE
#define IDIRECTORY_LISTER_FILE

class IDirectoryLister
{
    public:
      virtual bool open(const std::string& path, bool hidden) = 0;
      virtual std::string get() = 0;
};

#endif
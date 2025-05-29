/*
** EPITECH PROJECT, 2024
** Pool - Day 11
** File description:
** Directory Lister Header Interface
*/

#include <string>
#include <dirent.h>

#ifndef DIRECTORY_LISTER_FILE
#define DIRECTORY_LISTER_FILE

#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister
{
  protected: 
  DIR *_directory;
  bool _ignoreHidden;

    public:
      DirectoryLister();
      DirectoryLister(const std::string& path, bool hidden);
      ~DirectoryLister();
      bool open(const std::string& path, bool hidden) override;
      std::string get() override;
};

#endif

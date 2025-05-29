#include "DirectoryLister.hpp"
#include <dirent.h>
#include <iostream>

DirectoryLister::~DirectoryLister() {
  if (_directory != nullptr) {
    closedir(_directory);
    _directory = nullptr;
  }
}

DirectoryLister::DirectoryLister()
    : _directory(nullptr), _ignoreHidden(false){};

DirectoryLister::DirectoryLister(const std::string &path, bool hidden) {
  open(path, hidden);
};

bool DirectoryLister::open(const std::string &path, bool hidden) {
  _directory = opendir(path.c_str());
  _ignoreHidden = hidden;

  if (_directory == nullptr) {
    perror(path.c_str());
    closedir(_directory);
    return false;
  } else {
    return true;
  }
};

std::string DirectoryLister::get() {
  if (_directory == nullptr) {
    return "";
  }

  dirent *entry = readdir(_directory);

  while (entry != nullptr) {
    std::string entryName = entry->d_name;

    if (_ignoreHidden || (entryName.size() > 0 && entryName[0] != '.')) {
      return entryName;
    }

    entry = readdir(_directory);
  }

  return "";
};

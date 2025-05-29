/*
** EPITECH PROJECT, 2024
** A Game of Toys
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() { _data = ""; }

Picture::Picture(const Picture &copy) { _data = copy._data; }

Picture::Picture(const std::string &file) { getPictureFromFile(file); }

Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string &file) {
  std::string fileContent;
  std::ifstream ifs(file.c_str());

  if (!ifs.is_open()) {
    _data = "ERROR";
    return false;
  }

  while (std::getline(ifs, fileContent)) {
    _data += fileContent + '\n';
  }

  ifs.close();

  return true;
}

Picture &Picture::operator=(const Picture &copy) {
  _data = copy._data;
  return *this;
}
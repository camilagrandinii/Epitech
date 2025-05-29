#include "Picture.hpp"
#include <fstream>
#include <iostream>
#include <string>

Picture::Picture() {}

Picture::~Picture() {}

Picture::Picture(const std::string &file) {
  if (file.empty()) {
    _data = "";
    return;
  }

  if (!getPictureFromFile(file)) {
    _data = "ERROR";
  }
}

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

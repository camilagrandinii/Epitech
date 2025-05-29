/*
** EPITECH PROJECT, 2024
** Pool - Day 13
** File description:
** Algorithm Header
*/

#ifndef ALGORITHM_FILE
#define ALGORITHM_FILE

#include <iostream>

template<typename T> void swap(T &num1, T &num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

template<typename T> T min(const T &num1, const T &num2){
    if(num1 < num2){
      return num1;
    } else {
      return num2;
    }
}

template<typename T> T max(const T &num1, const T &num2){
  if(num1 < num2){
    return num2;
  } else {
    return num1;
  }
}

template<typename T> T clamp(const T num1, const T num2, const T num3){
    if(num2 < num1 && num1 < num3){
      return num1;
    }
    else if(num1 < num2 && num2 < num3){
      return num2;
    }
    else {
      return num3;
    }
}

#endif
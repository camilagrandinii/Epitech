#include "Student.hpp"
#include <format>
#include <iostream>
#include <algorithm>
#include <string>

Student::Student(std::string name) : _name(name), _energy_points(100)
{
    std::cout << "Student "<< name <<": I'm ready to learn C ++." << std::endl;
};

Student::~Student(){
    std::cout << "Student "<< Student::_name <<": Wow, much learning today very smart, such C ++." << std::endl;
}

void replaceSubStr(
    std::string &str,
    const std::string &subStr,
    const std::string &replacement)
{
    size_t pos = str.find(subStr);
    while (pos != std::string::npos)
    {
        str.replace(pos, subStr.length(), replacement);
        pos = str.find(subStr, pos + replacement.length());
    }
}

bool Student::learn(std::string subject)
{
    if(Student::_energy_points - 42 > 0){
        Student::_energy_points-=42;
        std::cout << "Student "<< Student::_name <<": " << subject << "" << std::endl; 
        return true;
    } else {
        replaceSubStr(subject, "C++", "shit");
        std::cout << "Student "<< Student::_name <<": " << subject << "" << std::endl; 
        return false;
    }
}

void Student::drink(std::string drink)
{
    if(drink == "Red Bull"){
        std::cout << "Student "<< Student::_name <<": Red Bull gives you wings!" << std::endl; 
        Student::_energy_points+=32;
    } else if(drink == "Monster"){
        std::cout << "Student "<< Student::_name <<": Unleash The Beast!" << std::endl; 
        Student::_energy_points+=64;
    } else {
        std::cout << "Student "<< Student::_name <<": ah, yes... enslaved moisture." << std::endl; 
        Student::_energy_points+=1;
    }
}

std::string Student::getName(Student *student){
    return student->_name;
}
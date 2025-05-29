#include <string>
#include "Student.hpp"
#ifndef Dean_HPP
#define Dean_HPP

struct Dean{
    ~Dean();
    
    Dean(std::string);

    std::string _name;
    bool _working;

    void giveDrink(Student*, std::string);
    std::string readDrink(std::string);

    void teachStudent(Student*, std::string);

    void timeCheck();
};

#endif
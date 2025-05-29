#include <string>
#include "Student.hpp"
#ifndef ASSISTANT_HPP
#define ASSISTANT_HPP

struct Assistant{
    ~Assistant();
    
    Assistant(int id);

    int _id;
    bool _working;

    void giveDrink(Student*, std::string);
    std::string readDrink(std::string);

    void helpStudent(Student*);

    void timeCheck();
};

#endif
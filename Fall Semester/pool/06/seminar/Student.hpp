#include <string>
#ifndef STUDENT_HPP
#define STUDENT_HPP

struct Student{
    ~Student();
    
    Student(std::string);

    std::string _name;
    int _energy_points;

    bool learn(std::string);
    void drink(std::string);
    std::string getName(Student*);
};

#endif
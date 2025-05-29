#include "Assistant.hpp"
#include "Student.hpp"
#include <format>
#include <iostream>
#include <fstream>
#include <string>

Assistant::Assistant(int id) : _id(id), _working(false)
{
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
};

Assistant::~Assistant()
{
    std::cout << "Assistant " << Assistant::_id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, std::string){
    std::cout << "Assistant " << Assistant::_id << ": drink this, " << student->_name << "" << std::endl;
}

std::string Assistant::readDrink(std::string studentName)
{
    std::ifstream ifs;
    std::string fileContent;
    ifs.open((studentName + ".drink").c_str());

    if (!ifs.is_open())
    {
        return "";
    }

    ifs >> fileContent;

    std::remove((studentName+".drink").c_str());

    std::cout << "Assistant " << Assistant::_id << ": " 
        << studentName << " needs a " << fileContent << " *sip coffee*" <<std::endl;

    return fileContent;
}

void Assistant::helpStudent(Student *student){
    std::string drink = readDrink(student->getName(student));

    if(drink == ""){
        std::cout << "Assistant " << Assistant::_id << ": " 
            << student->_name << " seems fine *sip coffee*" <<std::endl;
    } else {
        giveDrink(student, drink);
    }
}

void Assistant::timeCheck(){
    if(_working){
        _working = false;
        std::cout << "Assistant " << Assistant::_id 
            << ": Enough teaching for today *sip coffee*" <<std::endl;
    } else {
        _working = true;
        std::cout << "Assistant " << Assistant::_id 
            << ": Time to teach some serious business *sip coffee*" <<std::endl;
    }
}
#include "Dean.hpp"
#include "Student.hpp"
#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Dean::Dean(std::string name) : _name(name), _working(false)
{
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?" << std::endl;
};

Dean::~Dean()
{
    std::cout << "Dean " << Dean::_name << ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string subject)
{
    std::vector<std::string> drinkList = { "Cristaline" , "Monster" , "Evian" , "Red Bull" , "Sierra Springs" };

    if(!student->learn(subject)){
        std::cout << "Dean " << Dean::_name
            << ": All work and no play makes " << student->getName(student) << " a dull student." <<std::endl;

        std::fstream my_file;
	    my_file.open(student->_name+".drink", std::ios::out);

        if(my_file.is_open()){
            my_file << drinkList[std::rand()%5];
        }
    }
}

void Dean::timeCheck()
{
    if (_working)
    {
        _working = false;
        std::cout << "Dean " << Dean::_name
                  << ": Don't forget to close the windows when you leave." << std::endl;
    }
    else
    {
        _working = true;
        std::cout << "Dean " << Dean::_name
                  << ": Where is everyone?" << std::endl;
    }
}

int main(){
    Student *camila = new Student("camila");

    Dean dean = Dean("zezin 1");

    dean.teachStudent(camila, "ptgues");
    dean.teachStudent(camila, "francês");
    dean.teachStudent(camila, "ola, tudo bem com você");
    dean.teachStudent(camila, "ola, cole");

    return 0;
}
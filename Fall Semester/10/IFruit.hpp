/*
** EPITECH PROJECT, 2024
** Pool - Day 10
** File description:
** Fruit Header Interface
*/

#include <string>

#ifndef IFRUIT_FILE
#define IFRUIT_FILE

#include <string>

class IFruit
{
    public:
        ~IFruit() = default;
        virtual std::string getName() const = 0;
        virtual unsigned int getVitamins() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;

        void setName(std::string name);
        void setVitamins(size_t vitam);
        void setPeeled(std::string *peeled);
};

std::ostream &operator<<(std::ostream &, const IFruit &);

#endif
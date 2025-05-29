/*
** EPITECH PROJECT, 2024
** Pool - Day 12
** File description:
** Toy Header
*/

#ifndef TOY_FILE
#define TOY_FILE

#include <iostream>
#include <fstream>

#include "Picture.hpp"

class Toy
{
public:
    class Error
    {
    private:
    public:
        enum ErrorType {UNKNOWN, PICTURE, SPEAK};
        Error();
        ~Error();
        const std::string &what() const;
        const std::string &where() const;
        ErrorType type;
        std::string _what;
        std::string _where;
    };
    enum ToyType {BASIC_TOY, ALIEN, WOODY, BUZZ};
    Toy();
    Toy(const Toy &copy);
    Toy(ToyType type, const std::string &name, const std::string &filename);
    ~Toy();
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &filename);
    std::string getAscii() const;
    virtual void speak(const std::string &statement);
    virtual bool speak_es(const std::string &statement);
    Toy &operator=(const Toy &copy);
    const Toy::Error &getLastError() const;
    Toy& operator<<(const std::string &filename);
protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
    Toy::Error _error;
};

std::ostream &operator<<(std::ostream &, const Toy&);
std::ostream &operator<<(std::string &, const Toy&);

#endif
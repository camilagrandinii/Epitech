#include <string>
#include <iostream>
#include "Federation.hpp"
#include "Destination.hpp"

Federation::Starfleet::Ship::Ship(int lenght, int width, std::string name,
                                  short maxWarp) : _length(lenght), _width(width),
                                                   _name(name), _maxWarp(maxWarp),
                                                   _home(Destination::Destination::EARTH), _location(_home)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl
              << "It is "
              << _length << " m in length and " << _width
              << " m in width." << std::endl
              << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Ship::Ship(int lenght, int width, std::string name) : _length(lenght),
                                                                  _width(width), _name(name), _home(Destination::Destination::VULCAN), _location(_home)
{
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl
              << "It is "
              << _length << " m in length and " << _width
              << " m in width." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    Federation::Starfleet::Ship::_core = core;
    core->_coreReactor->setStability(true);
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
    {
        std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
    }
    else
    {
        std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
    }
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    Federation::Ship::_core = core;
    core->_coreReactor->setStability(true);
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
    {
        std::cout << _name << ": The core is stable at the time." << std::endl;
    }
    else
    {
        std::cout << _name << ": The core is unstable at the time." << std::endl;
    }
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    Ship::_captain = captain;

    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << Ship::_name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign" << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name){};

std::string Federation::Starfleet::Captain::getName()
{
    return Captain::_name;
}

int Federation::Starfleet::Captain::getAge()
{
    return Captain::_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    Captain::_age = age;
}

bool Federation::Starfleet::Ship::move(int warp, Destination::Destination d){
    if(warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp){
    if(warp <= _maxWarp && _core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination::Destination d){
    if(d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(){
    if(_core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp, Destination::Destination d){
    if(warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp){
    if(warp <= _maxWarp && _core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination::Destination d){
    if(d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(){
    if(_core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}
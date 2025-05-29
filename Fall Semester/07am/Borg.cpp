#include <string>
#include <iostream>
#include "Borg.hpp"
#include "Destination.hpp"

Borg::Ship::Ship() : _side(300), _maxWarp(9), _home(Destination::Destination::UNICOMPLEX), _location(_home)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." 
              << std::endl << "Your biological characteristics and technologies will be assimilated." 
              << std::endl << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    Borg::Ship::_core = core;
    core->_coreReactor->setStability(true);
}

void Borg::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
    {
        std::cout << "Everything is in order." << std::endl;
    }
    else
    {
        std::cout << "Critical failure imminent." << std::endl;
    }
}

bool Borg::Ship::move(int warp, Destination::Destination d){
    if(warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp){
    if(warp <= _maxWarp && _core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination::Destination d){
    if(d != _location && _core->_coreReactor->isStable()){
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(){
    if(_core->_coreReactor->isStable()){
        _location = _home;
        return true;
    }
    return false;
}

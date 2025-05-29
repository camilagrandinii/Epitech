#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef BORG_FILE
#define BORG_FILE

namespace Borg
{
    class Ship
    {
    public:
        WarpSystem::Core *_core;

        Ship();
        void setupCore(WarpSystem::Core *);
        void checkCore();
        bool move(int warp, Destination::Destination d); 
        bool move(int warp);                             
        bool move(Destination::Destination d);           
        bool move();                                     

    private:
        int _side;
        short _maxWarp;
        Destination::Destination _home;
        Destination::Destination _location;
    };
}

#endif
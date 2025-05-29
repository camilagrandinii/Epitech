#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef FEDERATION_FILE
#define FEDERATION_FILE

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        public:
            WarpSystem::Core *_core;

            Captain(std::string);
            std ::string getName();
            int getAge();
            void setAge(int age);

        private:
            std ::string _name;
            int _age;
        };

        class Ship
        {
        public:
            WarpSystem::Core *_core;

            Ship(int lenght, int width, std::string name, short maxWarp);
            void setupCore(WarpSystem::Core *);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp, Destination::Destination d); 
            bool move(int warp);                             
            bool move(Destination::Destination d);           
            bool move();                                     

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Captain *_captain;
            Destination::Destination _home;
            Destination::Destination _location;
        };

        class Ensign
        {
            std ::string _name;

        public:
            Ensign(std::string);
        };
    }

    class Ship
    {
    public:
        WarpSystem::Core *_core;

        Ship(int lenght, int width, std::string name);
        void setupCore(WarpSystem::Core *);
        void checkCore();
        bool move(int warp, Destination::Destination d); 
        bool move(int warp);                             
        bool move(Destination::Destination d);           
        bool move();                                     

    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination::Destination _home;
        Destination::Destination _location;
    };
}

#endif
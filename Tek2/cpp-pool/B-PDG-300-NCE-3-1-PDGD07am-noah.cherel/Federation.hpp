/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ship;
        class Ensign;
    }
    class Ship;
}

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"
#include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name);
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                int _shield;
                int _photonTorpedo;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home = EARTH;
        };
        class Ensign {
            public:
                Ensign(std::string name);
            private:
                std::string _name;
        };
        }
    class Ship {
        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            WarpSystem::Core *getCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
        private:
            int _length;
            int _width;
            short _maxWarp;
            int _shield;
            std::string _name;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home = VULCAN;
    };
}

#endif /* !FEDERATION_HPP_ */

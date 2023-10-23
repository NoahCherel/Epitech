/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg {
    class Ship;
}

#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Destination.hpp"

namespace Borg {
    class Ship {
        public:
            ~Ship();
            Ship(int weaponFrequency = 20, short repair = 3);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void repair();
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home = UNICOMPLEX;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Federation
*/

#include <iostream>
#include "Borg.hpp"
#include "Destination.hpp"
#include "WarpSystem.hpp"
#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _location = _home;
    _shield = 100;
    _photonTorpedo = torpedo;
    std::cout << "The ship USS " << name << " has been finished." <<std::endl;
    std:: cout <<"It is " << length << " m in length and " << width
    << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    _location = _home;
    _shield = 100;
    std::cout << "The ship USS " << _name << " has been finished." <<std::endl;
    std:: cout <<"It is " << _length << " m in length and " << _width
    << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo > 0) {
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        _photonTorpedo--;
        target->setShield(target->getShield() - 50);
        if (target->getShield() <= 0)
            std::cout << _name << ": Target destroyed." << std::endl;
        else
            std::cout << _name << ": Target shields at " << target->getShield() << "%." << std::endl;
    }
    else
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}


void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes > _photonTorpedo) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    if (_photonTorpedo > 0) {
        _photonTorpedo--;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
    } else
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _location = _home;
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is "<< length << " m in length and " << width << " m in width." << std::endl;
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return move(warp, _home);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool Federation::Starfleet::Ship::move()
{
    return move(_maxWarp, _home);
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    return move(_maxWarp, _home);
}

bool Federation::Ship::move(int warp)
{
    return move(warp, _home);
}

bool Federation::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
    _age = 0;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << name <<", awaiting orders." << std::endl;
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS "
    << _name << "." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << _name << ": The core is unstable at the time." << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return _core;
}

void Federation::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Ship::getShield()
{
    return _shield;
}

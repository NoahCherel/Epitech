/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Droid
*/

#include "Droid.hpp"
#include <iostream>
#include <string>
#include <ostream>

Droid::Droid(const std::string& serial) : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")), _battleData(new DroidMemory()) {
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(const Droid& other) : _id(other._id), _energy(50), _attack(other._attack), _toughness(other._toughness), _status(new std::string(*other._status)), _battleData(new DroidMemory(*other._battleData)) {
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid() {
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
    delete _status;
}

Droid& Droid::operator=(const Droid& other) {
    if (this != &other) {
        _energy = 50;
        _id = other._id;
        delete _status;
        _status = new std::string(*other._status);
        delete _battleData;
        _battleData = new DroidMemory(*other._battleData);
    }
    return *this;
}

bool Droid::operator==(const Droid& other) const {
    return *_status == *other._status;
}
bool Droid::operator!=(const Droid& other) const {
    return !(*this == other);
}

Droid& Droid::operator<<(size_t& energy) {
    if (_energy + energy > 100) {
        energy = energy - (100 - _energy);
        _energy = 100;
    }
    else {
        _energy += energy;
        energy = 0;
    }
    return *this;
}

std::string Droid::getId() const {
    return _id;
}

void Droid::setId(const std::string& id) {
    _id = id;
}

size_t Droid::getEnergy() const {
    return _energy;
}

void Droid::setEnergy(size_t energy) {
    _energy = energy;
}

std::string* Droid::getStatus() const {
    return _status;
}

void Droid::setStatus(std::string* status) {
    *_status = *status;
}

const size_t Droid::getAttack() const {
    return _attack;
}

const size_t Droid::getToughness() const {
    return _toughness;
}

void Droid::talk() {
    std::cout << "Droid '" << _id << "' " << *_status << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Droid& droid) {
    os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return os;
}

DroidMemory* Droid::getBattleData() const {
    return _battleData;
}

void Droid::setBattleData(DroidMemory* battleData) {
    _battleData = battleData;
}

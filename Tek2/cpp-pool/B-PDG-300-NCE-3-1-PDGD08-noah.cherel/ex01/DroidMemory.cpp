/*
** EPITECH PROJECT, 2023
** *
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _fingerprint(random()), _exp(0) {}

DroidMemory::DroidMemory(const DroidMemory& other) : _fingerprint(other._fingerprint), _exp(other._exp) {}

DroidMemory::~DroidMemory() {}

DroidMemory& DroidMemory::operator<<(DroidMemory const& droidmemory){
    this->_exp += droidmemory.getExp();
    this->_fingerprint ^= droidmemory.getFingerprint();
    return (*this);
}

DroidMemory& DroidMemory::operator>>(DroidMemory & droidmemory) const {
    droidmemory.setExp(this->_exp + droidmemory.getExp());
    droidmemory.setFingerprint(droidmemory.getFingerprint() ^ this->_fingerprint);
    return (droidmemory);
}

DroidMemory& DroidMemory::operator+=(const DroidMemory& other) {
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory& other) {
    DroidMemory tmp(*this);
    tmp += other;
    return tmp;
}

size_t DroidMemory::getFingerprint() const {
    return _fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint) {
    _fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const {
    return _exp;
}

void DroidMemory::setExp(size_t exp) {
    _exp = exp;
}

DroidMemory& DroidMemory::operator+=(size_t const& exp) {
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory& DroidMemory::operator+(size_t const&) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const DroidMemory& memory) {
    os << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp();
    return os;
}

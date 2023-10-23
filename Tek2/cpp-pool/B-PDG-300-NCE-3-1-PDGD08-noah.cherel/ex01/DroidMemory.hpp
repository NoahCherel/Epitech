/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>

class DroidMemory {
public:
    DroidMemory();
    DroidMemory(const DroidMemory& other);
    ~DroidMemory();
    DroidMemory& operator<<(DroidMemory const&);
    DroidMemory& operator>>(DroidMemory&) const;
    DroidMemory& operator+=(const DroidMemory& other);
    DroidMemory operator+(const DroidMemory& other);
    DroidMemory& operator+=(size_t const& exp);
    DroidMemory& operator+(size_t const&);

    size_t getFingerprint() const;
    void setFingerprint(size_t fingerprint);
    size_t getExp() const;
    void setExp(size_t exp);
private:
    size_t _fingerprint;
    size_t _exp;
};
std::ostream& operator<<(std::ostream& os, const DroidMemory& memory);

#endif /* !DROIDMEMORY_HPP_ */

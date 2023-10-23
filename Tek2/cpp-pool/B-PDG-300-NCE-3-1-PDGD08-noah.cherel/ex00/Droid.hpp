/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>

class Droid {
public:
    Droid();
    Droid(const std::string& serial);
    Droid(const Droid& other);
    ~Droid();
    Droid& operator=(const Droid& other);
    bool operator==(const Droid& other) const;
    bool operator!=(const Droid& other) const;
    Droid& operator<<(size_t& energy);

    std::string getId() const;
    void setId(const std::string& id);
    size_t getEnergy() const;
    void setEnergy(size_t energy);
    std::string* getStatus() const;
    void setStatus(std::string* status);
    const size_t getAttack() const;
    const size_t getToughness() const;
    void talk();

private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string* _status;
};

std::ostream& operator<<(std::ostream& os, const Droid& droid);


#endif /* !DROID_HPP_ */

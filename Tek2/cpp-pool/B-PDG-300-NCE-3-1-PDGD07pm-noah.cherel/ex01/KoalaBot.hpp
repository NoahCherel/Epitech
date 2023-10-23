/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP
#define KOALABOT_HPP

#include "Parts.hpp"
#include <string>
#include <iostream>

class KoalaBot
{
public:
    KoalaBot(std::string serial = "Bob-01");
    void setParts(const Arms& arms);
    void setParts(const Legs& legs);
    void setParts(const Head& head);
    void swapParts(Arms& arms);
    void swapParts(Legs& legs);
    void swapParts(Head& head);
    bool status() const;
    void informations() const;

private:
    std::string m_serial;
    Arms m_arms;
    Legs m_legs;
    Head m_head;
};

#endif /* !KOALABOT_HPP_ */

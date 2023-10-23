/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** KoalaBot
*/

#include "Parts.hpp"
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) :
    m_serial(serial), m_arms(), m_legs(), m_head()
{
}

void KoalaBot::setParts(const Arms& arms)
{
    m_arms = arms;
}

void KoalaBot::setParts(const Legs& legs)
{
    m_legs = legs;
}

void KoalaBot::setParts(const Head& head)
{
    m_head = head;
}

void KoalaBot::swapParts(Arms& arms)
{
    Arms tmp = m_arms;
    m_arms = arms;
    arms = tmp;
}

void KoalaBot::swapParts(Legs& legs)
{
    Legs tmp = m_legs;
    m_legs = legs;
    legs = tmp;
}

void KoalaBot::swapParts(Head& head)
{
    Head tmp = m_head;
    m_head = head;
    head = tmp;
}

bool KoalaBot::status() const
{
    if (m_arms.isFunctional() && m_legs.isFunctional() && m_head.isFunctional())
        return true;
    else
        return false;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << m_serial << std::endl;
    m_arms.informations();
    m_legs.informations();
    m_head.informations();
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms() : m_functional(true), m_serial("A-01")
{}

bool Arms::isFunctional() const
{
    return m_functional;
}

void Arms::setSerial(std::string serial)
{
    m_serial = serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << m_serial << " status : " << (m_functional ? "OK" : "KO") << std::endl;
}

Legs::Legs() : m_functional(true), m_serial("L-01")
{}

bool Legs::isFunctional() const
{
    return m_functional;
}

void Legs::setSerial(std::string serial)
{
    m_serial = serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << m_serial << " status : " << (m_functional ? "OK" : "KO") << std::endl;
}

Head::Head() : m_functional(true), m_serial("H-01")
{}

bool Head::isFunctional() const
{
    return m_functional;
}

void Head::setSerial(std::string serial)
{
    m_serial = serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << m_serial << " status : " << (m_functional ? "OK" : "KO") << std::endl;
}
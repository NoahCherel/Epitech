/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Parts
*/

#ifndef PARTS_HPP
#define PARTS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Arms
{
    public:
        Arms();
        bool isFunctional() const;
        void informations() const;
        void setSerial(std::string serial);
    private:
        bool m_functional;
        std::string m_serial;
};

class Legs
{
    public:
        Legs();
        bool isFunctional() const;
        void informations() const;
        void setSerial(std::string serial);
    private:
        bool m_functional;
        std::string m_serial;
};

class Head
{
    public:
        Head();
        bool isFunctional() const;
        void informations() const;
        void setSerial(std::string serial);
    private:
        bool m_functional;
        std::string m_serial;
};

#endif /* !PARTS_HPP_ */

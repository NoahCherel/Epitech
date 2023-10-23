/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** KreogCom
*/

#include "KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial)
{
    this->x = x;
    this->y = y;
    this->m_serial = serial;
    this->next = NULL;
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);
    newCom->next = this->next;
    this->next = newCom;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->next;
    this->next = this->next->next;
    delete tmp;
}

KreogCom *KreogCom::getCom()
{
    return this->next;
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << m_serial << " currently at " << x << " " << y << std::endl;
}

void KreogCom::locateSquad()
{
    KreogCom* current = next;
    while (current != nullptr)
    {
        current->ping();
        current = current->next;
    }
    ping();
}

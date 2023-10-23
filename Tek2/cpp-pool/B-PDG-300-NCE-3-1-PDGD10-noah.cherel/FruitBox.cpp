/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <iostream>

FruitBox::FruitBox(unsigned int size)
{
    this->size = size;
    nb_fruits = 0;
}

FruitBox::~FruitBox()
{
    for (IFruit *fruit : fruits)
        delete fruit;
}

unsigned int FruitBox::getSize() const
{
    return size;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (nb_fruits < size) {
        fruits.push_back(fruit);
        nb_fruits++;
        return true;
    }
    return false;
}

IFruit *FruitBox::popFruit()
{
    if (nb_fruits == 0)
        return nullptr;
    IFruit *fruit = fruits[0];
    fruits.erase(fruits.begin());
    nb_fruits--;
    return fruit;
}

IFruit *FruitBox::pickFruit()
{
    if (nb_fruits == 0)
        return nullptr;
    return fruits.back();
}

unsigned int FruitBox::nbFruits() const
{
    return nb_fruits;
}

std::vector<IFruit *> FruitBox::getFruits() const
{
    return fruits;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &fruitBox)
{
    bool first = true;
    os << "[";
    for (IFruit *fruit : fruitBox.getFruits()) {
        if (!first)
            os << ", ";
        first = false;
        os << "[name: \"" << fruit->getName() << "\", vitamins: " << fruit->getVitamins() << ", peeled: " << std::boolalpha << fruit->isPeeled() << "]"; 
    }
    os << "]";
    return os;
}
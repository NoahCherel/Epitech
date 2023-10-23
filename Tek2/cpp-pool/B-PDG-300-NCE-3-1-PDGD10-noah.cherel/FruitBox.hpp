/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "IFruit.hpp"
#include <iostream>
#include <string>
#include <vector>

class FruitBox {
    public:
        FruitBox(unsigned int size);
        ~FruitBox();
        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit* fruit);
        IFruit* pickFruit();
        IFruit* popFruit();
        friend std::ostream& operator<<(std::ostream& os, const FruitBox& box);
        std::vector<IFruit*> getFruits() const;
    private:
        std::vector<IFruit*> fruits;
        unsigned int size;
        unsigned int nb_fruits;
};

#endif /* !FRUITBOX_HPP_ */

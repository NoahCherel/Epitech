/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    IFruit *fruit = unsorted.pickFruit();
    while (fruit != nullptr) {
        if (fruit->getName() == "lemon")
            lemon.pushFruit(fruit);
        else if (fruit->getName() == "bloodorange" || fruit->getName() == "orange" || fruit->getName() == "grapefruit")
            citrus.pushFruit(fruit);
        else if (fruit->getName() == "strawberry" || fruit->getName() == "raspberry")
            berry.pushFruit(fruit);
        fruit = unsorted.pickFruit();
    }
}
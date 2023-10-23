/*
** EPITECH PROJECT, 2023
** MyGKrellm.cpp
** File description:
** rush 3
*/

#include "MyGKrellm.hpp"
#include "./GraphicMode/GraphicClass.hpp"
#include "./TextMode/TextClass.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstring>

int main(int ac, char **av)
{
    /*if (ac != 2)
        return 84;*/
    if (ac >= 2) {
        if (strcmp(av[1], "-g") == 0 || strcmp(av[1], "--graphic") == 0) {
            GraphicClass *graphic = new GraphicClass();
        } else {
            TextClass *text = new TextClass();
        }
    } else {
        TextClass *text = new TextClass();
    }
    return 0;
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include <vector>
#include <iostream>
#include <memory>

#include "../Include/Parser.hpp"
#include "../Include/Circuit.hpp"
#include "../Include/Input.hpp"
#include "../Include/Output.hpp"

int main(int ac, char **av)
{
    Parser parser;
    Circuit circuit;

    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }
    try {
        parser.parseFile(av[1]);
    }
    catch (const std::exception &e) {
        printf("Error");
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

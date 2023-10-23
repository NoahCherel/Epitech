/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** buffer
*/

#include "../include/core.hpp"


std::vector<std::vector<sf::Color>> generate_buffer(int width, int height)
{
    // Creates a 2D vector of sf::Color (Black) of the size of the generated image
    std::vector<std::vector<sf::Color>> framebuffer;
    for (int y = 0; y < height; y++) {
        std::vector<sf::Color> line;
        for (int x = 0; x < width; x++) {
            line.push_back(sf::Color(0, 0, 0));
        }
        framebuffer.push_back(line);
    }
    return framebuffer;
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** display
*/

#include "../include/core.hpp"


void display_ppm(std::vector<std::vector<sf::Color>> &framebuffer)
{
    // Displays the generated image as a ppm file in the terminal
    std::cout << "P3" << std::endl;
    std::cout << framebuffer[0].size() << " " << framebuffer.size() << std::endl;
    std::cout << "255" << std::endl;
    for (int y = 0; y < (int)framebuffer.size(); y++) {
        for (int x = 0; x < (int)framebuffer[y].size(); x++) {
            std::cout << (int)framebuffer[y][x].r << " " << (int)framebuffer[y][x].g << " " << (int)framebuffer[y][x].b << std::endl;
        }
    }
}

void output_ppm(std::vector<std::vector<sf::Color>> &framebuffer, std::string filename)
{
    // Displays the generated image as a ppm file in the terminal
    std::ofstream ofs;
    ofs.open(filename);
    ofs << "P3\n" << framebuffer[0].size() << " " << framebuffer.size() << "\n255\n";
    for (int y = 0; y < (int)framebuffer.size(); y++) {
        for (int x = 0; x < (int)framebuffer[y].size(); x++) {
            ofs << (int)framebuffer[y][x].r << " " << (int)framebuffer[y][x].g << " " << (int)framebuffer[y][x].b << "\n";
        }
    }
    ofs.close();
}

void display_window(std::vector<std::vector<sf::Color>> &framebuffer)
{
    // Creates a window and displays the generated image
    sf::RenderWindow window(sf::VideoMode(framebuffer[0].size(), framebuffer.size()), "Raytracer");
    sf::Texture texture;
    texture.create(framebuffer[0].size(), framebuffer.size());
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Image image;
    image.create(framebuffer[0].size(), framebuffer.size());
    for (int y = 0; y < (int)framebuffer.size(); y++) {
        for (int x = 0; x < (int)framebuffer[y].size(); x++) {
            image.setPixel(x, y, framebuffer[y][x]);
        }
    }
    texture.update(image);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}

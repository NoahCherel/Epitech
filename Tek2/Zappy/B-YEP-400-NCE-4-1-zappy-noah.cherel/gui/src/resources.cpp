/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** ressources.cpp
*/

#include "../include/game.hpp"

void Resources::displayBct(std::vector<std::string> bct)
{
    for (const auto &i : bct) {
        std::cout << i << std::endl;
    }
}

sf::Text Game::setText(const sf::Font& font, std::string text, sf::Vector2f pos, int size, sf::Color color)
{
    sf::Text textToDisplay;
    textToDisplay.setFont(font);
    textToDisplay.setString(text);
    textToDisplay.setCharacterSize(size);
    textToDisplay.setFillColor(color);
    textToDisplay.setOutlineColor(sf::Color::Black);
    textToDisplay.setOutlineThickness(2);
    textToDisplay.setPosition(pos);
    return textToDisplay;
}

sf::Sprite Game::createTextbar(const sf::Texture& HotbarTexture, CommandServer cmdServ, sf::Vector2f rect, sf::Vector2f scale)
{
    sf::Sprite sprite(HotbarTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, rect.x, rect.y));
    if (cmdServ.msz[0] * SIZE_BLOCK >= 1920) {
        _posTextbox.x = (1920 - 840) / 2;
    } else {
        _posTextbox.x = -((1920 - cmdServ.msz[0] * SIZE_BLOCK) / 2 - (1920 - 840) / 2 - 50);
    }
    if (cmdServ.msz[1] * SIZE_BLOCK >= 1920) {
        _posTextbox.y = 800;
    } else {
        _posTextbox.y = -((1080 - cmdServ.msz[1] * SIZE_BLOCK) / 2 - 800);
        std::cout << _posTextbox.y << std::endl;
    }
    sprite.setPosition(_posTextbox.x, _posTextbox.y);
    sprite.setScale(scale.x, scale.y);
    return sprite;
}

std::vector<sf::Sprite> Game::createResource(const sf::Texture& blockTexture, std::vector<std::string> bct, std::vector<std::vector<std::vector<std::vector<int>>>> PosResource)
{
    Utils utils;
    std::vector<sf::Sprite> sprites;
    sf::Sprite sprite(blockTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    std::vector<std::vector<int>> intMatrix = utils.convertStringVectorTo2DIntVector(bct);
    std::cout << "intMatrix.size() = " << intMatrix.size() << "\n";
    for (std::vector<int>::size_type y = 0; y < intMatrix.size(); y++) {
        for (std::vector<int>::size_type x = 2; x < intMatrix[y].size(); x++) {
            if (intMatrix[y][x] != 0) {
                sprite.setTextureRect(sf::IntRect((x - 1) * 32, 0, 32, 32));
                sprite.setPosition(intMatrix[y][0] * SIZE_BLOCK + PosResource[intMatrix[y][0]][intMatrix[y][1]][x - 2][0], intMatrix[y][1] * SIZE_BLOCK + PosResource[intMatrix[y][0]][intMatrix[y][1]][x - 2][1]);
                sprites.push_back(sprite);
            }
        }
    }
    return sprites;
}

std::vector<sf::Sprite> Game::updateResources(const sf::Texture& blockTexture, std::vector<sf::Sprite>& sprites, std::vector<std::vector<int>> intMatrix)
{
    std::vector<sf::Sprite> updatedSprites;
    sf::Sprite sprite(blockTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    for (std::vector<int>::size_type y = 0; y < intMatrix.size(); y++) {
        for (std::vector<int>::size_type x = 2; x < intMatrix[y].size(); x++) {
            if (intMatrix[y][x] != 0) {
                for (int i = 0; i < intMatrix[y][x]; i++) {
                    sprite.setTextureRect(sf::IntRect((x - 1) * 32, 0, 32, 32));
                    sprite.setOrigin(16, 16);
                    sprite.setScale(rotation, 1);
                    sprite.setPosition(intMatrix[y][0] * SIZE_BLOCK + _PosResource[intMatrix[y][0]][intMatrix[y][1]][x - 2][0] + 16, intMatrix[y][1] * SIZE_BLOCK + _PosResource[intMatrix[y][0]][intMatrix[y][1]][x - 2][1] + 16);
                    updatedSprites.push_back(sprite);
                }
            }
        }
    }
    sprites = updatedSprites;
    return updatedSprites;
}

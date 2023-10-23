/*
** EPITECH PROJECT, 2023
** KOBAN
** File description:
** map.cpp
*/

#include "../include/game.hpp"

sf::Texture Game::loadTexture(const std::string& imageBlockPath)
{
    sf::Texture texture;
    if (!texture.loadFromFile(imageBlockPath)) {
        std::cout << "Failed to load" << imageBlockPath << std::endl;
    }
    return texture;
}

void Game::initializeMap(CommandServer cmdServ)
{
    Utils utils;
    setCubeIndices(utils.createRandomList(cmdServ.msz[0] * cmdServ.msz[1], 4));
    setWaterIndices(utils.createRandomList((cmdServ.msz[0] + 10) * (cmdServ.msz[1] + 10), 2));
}

std::vector<sf::Sprite> Game::createCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock)
{
    std::vector<sf::Sprite> cubes;
    waterCubes = createWaterCubes(blockTexture, sizeX, sizeY, sizeBlock);
    cubes.insert(cubes.end(), waterCubes.begin(), waterCubes.end());
    std::vector<sf::Sprite> terrainCubes = createTerrainCubes(blockTexture, sizeX, sizeY, sizeBlock);
    cubes.insert(cubes.end(), terrainCubes.begin(), terrainCubes.end());
    return cubes;
}

std::vector<sf::Sprite> Game::createWaterCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock)
{
    std::vector<sf::Sprite> waterCubes;
    sf::Sprite water;
    water.setTexture(blockTexture);
    water.setTextureRect(sf::IntRect(0, 160, 32, 32));
    int waterIndex = 0;
    int xPos = -5 * sizeBlock;
    int yPos = -5 * sizeBlock;
    for (int i = 0; i < ((sizeX * 2) + 10) * ((sizeY * 2) + 10); i++) {
        water.setScale(sizeBlock / 32, sizeBlock / 32);
        water.setTextureRect(sourceRectWater);
        water.setPosition(xPos, yPos);
        waterCubes.push_back(water);
        xPos += sizeBlock;
        if (++waterIndex >= (int)getWaterIndices().size()) waterIndex = 0;
        if (xPos >= ((sizeX * 2) + 10) * sizeBlock) {
            xPos = -5 * sizeBlock;
            yPos += sizeBlock;
        }
    }
    return waterCubes;
}

std::vector<sf::Sprite> Game::createTerrainCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock)
{
    std::vector<sf::Sprite> terrainCubes;
    sf::Sprite sprite(blockTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, sizeBlock, sizeBlock));
    int cubeIndex = 0;
    int xPos = 0;
    int yPos = 0;
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (x <= (sizeX / 10 - 1) || y <= (sizeY / 10 - 1) || x >= (sizeX - (sizeX / 10)) || y >= (sizeY - (sizeY / 10))) {
                sf::Sprite cube(blockTexture);
                cube.setTextureRect(sf::IntRect(0, 128, 32, 32));
                cube.setScale(sizeBlock / 32, sizeBlock / 32);
                cube.setPosition(xPos, yPos);
                terrainCubes.push_back(cube);
            } else {
                sprite.setScale(sizeBlock / 32, sizeBlock / 32);
                sprite.setTextureRect(sf::IntRect(0, 32 * getCubeIndices()[cubeIndex], 32, 32));
                sprite.setPosition(xPos, yPos);
                terrainCubes.push_back(sprite);
            }
            cubeIndex++;
            xPos += sizeBlock;
        }
        xPos = 0;
        yPos += sizeBlock;
    }
    return terrainCubes;
}

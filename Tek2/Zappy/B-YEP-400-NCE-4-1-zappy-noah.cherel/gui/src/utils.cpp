/*
** EPITECH PROJECT, 2023
** KOBAN
** File description:
** utils.cpp
*/

#include "../include/game.hpp"

std::vector<std::vector<int>> Utils::convertStringVectorTo2DIntVector(const std::vector<std::string>& stringVector) {
    std::vector<std::vector<int>> intMatrix;
    for (const std::string& str : stringVector) {
        std::stringstream ss(str);
        std::vector<int> row;
        int intValue;
        while (ss >> intValue) {
            row.push_back(intValue);
        }
        intMatrix.push_back(row);
    }
    return intMatrix;
}

std::vector<std::vector<std::vector<std::vector<int>>>> Utils::addRandomValue(int sizeX, int sizeY, int sizeZ) {
    std::vector<std::vector<std::vector<std::vector<int>>>> tableau(sizeX, std::vector<std::vector<std::vector<int>>>(sizeY, std::vector<std::vector<int>>(sizeZ, std::vector<int>(2))));

    // Initialiser le générateur de nombres aléatoires avec une graine basée sur l'horloge système
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ajouter des valeurs aléatoires entre 0 et 64 à chaque élément du tableau
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            for (int k = 0; k < sizeZ; ++k) {
                tableau[i][j][k][0] = std::rand() % 65; // Valeur aléatoire entre 0 et 64 pour l'indice X
                tableau[i][j][k][1] = std::rand() % 65; // Valeur aléatoire entre 0 et 64 pour l'indice Y
            }
        }
    }
    return tableau;
}

std::vector<int> Utils::createRandomList(int size, int max)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> cubeIndices;
    for (int i = 0; i < size; i++) {
        int rdm = rand() % max;
        cubeIndices.push_back(rdm);
    }
    return cubeIndices;
}

std::vector<std::vector<std::string>> Utils::divideVector(const std::vector<std::string>& vector, int size)
{
    std::vector<std::vector<std::string>> vecteursDivises;
    int nbVecteurs = (vector.size() + size - 1) / size; // Calcul du nombre de vecteurs nécessaires
    for (int i = 0; i < nbVecteurs; i++) {
        std::vector<std::string> vectorDivided;
        int debut = i * size;
        int end = std::min(debut + size, (int)vector.size());

        for (int j = debut; j < end; j++) {
            vectorDivided.push_back(vector[j]);
        }

        vecteursDivises.push_back(vectorDivided);
    }
    return vecteursDivises;
}

void Utils::modifyImagePixels(sf::Image& image, const sf::Color& green, const sf::Color& red, const sf::Color& color, const sf::Color& revColor) {
    unsigned int width = image.getSize().x;
    unsigned int height = image.getSize().y;

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            sf::Color pixelColor = image.getPixel(x, y);

            if (pixelColor == green) {
                // Modify the pixel if its color matches the target color
                image.setPixel(x, y, color);
            } else if (pixelColor == red) {
                // Modify the pixel if its color matches the target color
                image.setPixel(x, y, revColor);
            }
        }
    }
}

sf::RectangleShape Utils::setRectangle(sf::RectangleShape rectangle, sf::Vector2f pos, sf::Vector2f size, sf::Color color, int fillColor)
{
    rectangle.setPosition(pos);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    color.a = fillColor;
    rectangle.setFillColor(color);
    return rectangle;
}

sf::SoundBuffer Utils::setSoundBuffer(sf::SoundBuffer soundBuffer, std::string path)
{
    soundBuffer.loadFromFile(path);
    return soundBuffer;
}

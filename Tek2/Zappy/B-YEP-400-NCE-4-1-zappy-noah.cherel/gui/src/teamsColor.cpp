/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** teamsColor
*/

#include "../include/teamsColor.hpp"

sf::Color TeamColor::createRandomColor()
{
    // Création d'un générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 255);
    // Génération de composantes aléatoires pour la couleur
    int red = dis(gen);
    int green = dis(gen);
    int blue = dis(gen);
    sf::Color color = sf::Color(red, green, blue);
    return color;
}

std::vector<TeamColor> TeamColor::createTeamsColors(std::vector<std::string> tna)
{
    std::vector<TeamColor> teamsColors;
    for (std::size_t i = 0; i < tna.size(); i++) {
        sf::Color color = createRandomColor();
        // Check if color is already used
        for (std::size_t j; j < teamsColors.size(); j++) {
            if (color == teamsColors[j].getColor()) {
                color = createRandomColor();
                j = 0;
            }
        }
        sf::Color reverseColor = sf::Color(255 - color.r, 255 - color.g, 255 - color.b);
        TeamColor teamColor(tna[i], color, reverseColor);
        // print team color
        teamsColors.push_back(teamColor);
    }
    return teamsColors;
}
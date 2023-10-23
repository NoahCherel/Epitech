/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** egg
*/

#include "../include/egg.hpp"

Egg::Egg(const std::vector<std::string>& enw)
{
    _eggId = std::stoi(enw[0]);
    _posX = std::stoi(enw[2]);
    _posY = std::stoi(enw[3]);
}

void Egg::processNewEgg(const std::vector<std::string>& enw, const std::vector<TeamColor>& teamsColors, std::vector<Egg>& eggs, std::vector<Player>& players,std::vector<std::vector<sf::Texture>>& textures)
{
    if (enw.size() > 0) {
        for (std::size_t i = 0; i < eggs.size(); i++) {
            if (eggs[i].getEggId() == std::stoi(enw[0])) {
                std::cout << "Egg already exist" << std::endl;
                return;
            }
        }
    }
    Egg egg(enw);
    Player player;
    for (std::size_t i = 0; i < players.size(); i++) {
        if (players[i].getId() == std::stoi(enw[1])) {
            player = players[i];
            break;
        }
    }
    std::size_t x = 0;
    for (; x < teamsColors.size(); x++) {
        if (teamsColors[x].getTeamName() == player.getTeamName()) {
            egg.setTeamName(player.getTeamName());
            egg.setTexture(textures[x][1]);
            egg.setSprite(sf::Sprite(textures[x][1]));
            // egg.getSprite().setTextureRect(sf::IntRect(128, 160, 32, 32));
            // egg.getSprite().setScale(3, 3);
            // egg.getSprite().setPosition(egg.getPosX() * 96, egg.getPosY() * 96);
            break;
        }
    }
    eggs.push_back(egg);
}

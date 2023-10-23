/*
** EPITECH PROJECT, 2023
** KOBAN
** File description:
** player.cpp
*/

#include "../include/player.hpp"

Player::Player(const std::vector<std::string>& pnw)
{
    try {
        _id = std::stoi(pnw[0]);
        _posX = std::stoi(pnw[1]);
        _posY = std::stoi(pnw[2]);
        _orientation = std::stoi(pnw[3]);
        _level = std::stoi(pnw[4]);
        _team = pnw[5];
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        _id = 0;
        _posX = 0;
        _posY = 0;
        _orientation = 0;
        _level = 0;
        _team = "";
    }
}

void Player::setPlayerColors(const std::vector<TeamColor>& teamsColors, Player& player, sf::Color& color, sf::Color& revColor) {
    for (std::size_t i = 0; i < teamsColors.size(); i++) {
        if (player.getTeamName() == teamsColors[i].getTeamName()) {
            color = teamsColors[i].getColor();
            revColor = teamsColors[i].getRevColor();
            break;
        }
    }
}

sf::Sprite Player::createSpriteFromTexture(sf::Texture& texture, int orientation, int level, int posX, int posY) {
    sf::Sprite sprite;
    sprite.setTexture(texture);
    if (orientation == 1) orientation = 3;
    else if (orientation == 3) orientation = 1;
    sprite.setTextureRect(sf::IntRect((orientation - 1) * 640, (level - 1) * 256, 160, 256));
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(80, 256);
    sprite.setPosition(posX * 96 + 48, posY * 96 + 72);
    return sprite;
}

void Player::printPlayer(const Player& player) {
    std::cout << "New player: " << player.getId() << " " << player.getPosX() << " " << player.getPosY() << " " << player.getOrientation() << " " << player.getLevel() << " " << player.getTeamName() << std::endl;
}

void Player::printAllPlayers(const std::vector<Player>& players) {
    std::cout << "Players: " << std::endl;
    for (std::size_t i = 0; i < players.size(); i++) {
        std::cout << "  - " << players[i].getId() << " " << players[i].getPosX() << " " << players[i].getPosY() << " " << players[i].getOrientation() << " " << players[i].getLevel() << " " << players[i].getTeamName() << std::endl;
    }
    std::cout << std::endl;
}

void Player::processPlayerPosition(const std::vector<std::string>& ppo, std::vector<Player>& players, const std::vector<TeamColor>& teamsColors, std::vector<std::vector<sf::Texture>>& textures) {
    if (ppo.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(ppo[0])) {
                    players[i].setPosX(std::stoi(ppo[1]));
                    players[i].setPosY(std::stoi(ppo[2]));
                    players[i].setOrientation(std::stoi(ppo[3]));

                    std::size_t x = 0;
                    for (; x < teamsColors.size(); x++) {
                        if (teamsColors[x].getTeamName() == players[i].getTeamName()) {
                            break;
                        }
                    }
                    players[i].setSprite(createSpriteFromTexture(textures[x][0], players[i].getOrientation(), players[i].getLevel(), players[i].getPosX(), players[i].getPosY()));
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerLevel(const std::vector<std::string>& plv, std::vector<Player>& players, const std::vector<TeamColor>& teamsColors, std::vector<std::vector<sf::Texture>>& textures) {
    if (plv.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(plv[0])) {
                    players[i].setLevel(std::stoi(plv[1]));
                    std::size_t x = 0;
                    for (; x < teamsColors.size(); x++) {
                        if (teamsColors[x].getTeamName() == players[i].getTeamName()) {
                            break;
                        }
                    }
                    players[i].setSprite(createSpriteFromTexture(textures[x][0], players[i].getOrientation(), players[i].getLevel(), players[i].getPosX(), players[i].getPosY()));
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerDrop(const std::vector<std::string>& pdr, std::vector<Player>& players) {
    if (pdr.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pdr[0])) {
                    if (std::stoi(pdr[1]) == 0) players[i].setFood(players[i].getFood() - 1);
                    else if (std::stoi(pdr[1]) == 1) players[i].setLinemate(players[i].getLinemate() - 1);
                    else if (std::stoi(pdr[1]) == 2) players[i].setDeraumere(players[i].getDeraumere() - 1);
                    else if (std::stoi(pdr[1]) == 3) players[i].setSibur(players[i].getSibur() - 1);
                    else if (std::stoi(pdr[1]) == 4) players[i].setMendiane(players[i].getMendiane() - 1);
                    else if (std::stoi(pdr[1]) == 5) players[i].setPhiras(players[i].getPhiras() - 1);
                    else if (std::stoi(pdr[1]) == 6) players[i].setThystame(players[i].getThystame() - 1);
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerPickup(const std::vector<std::string>& pgt, std::vector<Player>& players) {
    if (pgt.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pgt[0])) {
                    if (std::stoi(pgt[1]) == 0) players[i].setFood(players[i].getFood() + 1);
                    else if (std::stoi(pgt[1]) == 1) players[i].setLinemate(players[i].getLinemate() + 1);
                    else if (std::stoi(pgt[1]) == 2) players[i].setDeraumere(players[i].getDeraumere() + 1);
                    else if (std::stoi(pgt[1]) == 3) players[i].setSibur(players[i].getSibur() + 1);
                    else if (std::stoi(pgt[1]) == 4) players[i].setMendiane(players[i].getMendiane() + 1);
                    else if (std::stoi(pgt[1]) == 5) players[i].setPhiras(players[i].getPhiras() + 1);
                    else if (std::stoi(pgt[1]) == 6) players[i].setThystame(players[i].getThystame() + 1);
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerInventory(const std::vector<std::string>& pin, std::vector<Player>& players) {
    if (pin.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pin[0])) {
                    players[i].setFood(std::stoi(pin[3]));
                    players[i].setLinemate(std::stoi(pin[4]));
                    players[i].setDeraumere(std::stoi(pin[5]));
                    players[i].setSibur(std::stoi(pin[6]));
                    players[i].setMendiane(std::stoi(pin[7]));
                    players[i].setPhiras(std::stoi(pin[8]));
                    players[i].setThystame(std::stoi(pin[9]));
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerDeath(std::string& pdi, std::vector<Player>& players) {
    if (pdi.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pdi)) {
                    players.erase(players.begin() + i);
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processPlayerBroadcast(const std::vector<std::string>& pbc, std::vector<Player>& players) {
    if (pbc.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pbc[0])) {
                    players[i].setBroadcast(std::stoi(pbc[1]));
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "This player doesn't exist" << std::endl;
}

void Player::processNewPlayer(const std::vector<std::string>& pnw, const std::vector<TeamColor>& teamsColors, std::vector<Player>& players, std::vector<std::vector<sf::Texture>>& textures) {
    if (pnw.size() > 0) {
        for (std::size_t i = 0; i < players.size(); i++) {
            try {
                if (players[i].getId() == std::stoi(pnw[0])) {
                    std::cout << "This player already exists" << std::endl;
                    return;
                }
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    Player newPlayer(pnw);
    sf::Color color;
    sf::Color revColor;
    setPlayerColors(teamsColors, newPlayer, color, revColor);

    std::size_t x = 0;
    for (; x < teamsColors.size(); x++) {
        if (teamsColors[x].getTeamName() == newPlayer.getTeamName()) {
            newPlayer.setTexture(textures[x][0]);
            break;
        }
    }
    sf::Sprite sprite = createSpriteFromTexture(textures[x][0], newPlayer.getOrientation(), newPlayer.getLevel(), newPlayer.getPosX(), newPlayer.getPosY());
    newPlayer.setSprite(sprite);
    // printPlayer(newPlayer);
    newPlayer.setFood(10);
    newPlayer.setLinemate(0);
    newPlayer.setDeraumere(0);
    newPlayer.setSibur(0);
    newPlayer.setMendiane(0);
    newPlayer.setPhiras(0);
    newPlayer.setThystame(0);
    players.push_back(newPlayer);
}

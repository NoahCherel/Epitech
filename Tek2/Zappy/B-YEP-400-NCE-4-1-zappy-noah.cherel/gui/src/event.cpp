/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** event.cpp
*/

#include "../include/game.hpp"

void Game::eventR()
{
    textbox = false;
    teamsInfo = false;
    playerInfo = false;
    nbrTeam = -1;
}

void Game::eventT(CommandServer cmdServ)
{
    playerInfo = false;
    textbox = false;
    teamsInfo = true;
    if (nbrTeam >= (int)cmdServ.teamName.size() - 1)
        nbrTeam = 0;
    else
        nbrTeam++;
    nameTeam.setString("Team: " + cmdServ.teamName[nbrTeam]);
}

void Game::eventU(CommandServer cmdServ)
{
    if (idSelectPlayer != -1) {
        textbox = true;
        teamsInfo = false;
        playerInfo = false;
        nbrTeam = -1;
        idSelectPlayer = -1;
        tempsbct = cmdServ.bct[getBctClick().x + getBctClick().y * cmdServ.msz[0]];
        setNbrResPos(tempsbct);
    }
}

void Game::eventMouseClickLeft(CommandServer cmdServ, sf::Event event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        nbrTeam = -1;
        teamsInfo = false;
        _posClick.x = event.mouseButton.x + getCameraPosition().x;
        _posClick.y = event.mouseButton.y + getCameraPosition().y;
        setBctClick(sf::Vector2i(std::floor(static_cast<double>(_posClick.x) / SIZE_BLOCK), std::floor(static_cast<double>(_posClick.y) / SIZE_BLOCK)));
        if (_posClick.x >= 0 && _posClick.y >= 0 && _posClick.x < cmdServ.msz[0] * SIZE_BLOCK && _posClick.y < cmdServ.msz[1] * SIZE_BLOCK) {
            int count = 0;
            for (std::size_t i = 0; i < _players.size(); i++) {
                if (getBctClick().x == _players[i].getPosX() && _bctClick.y == _players[i].getPosY()) {
                    idSelectPlayer = _players[i].getId();
                    std::cout << "Player selected: " << idSelectPlayer << std::endl;
                    count += 1;
                }
            }
            if (count == 0) {
                textbox = true;
                playerInfo = false;
                tempsbct = cmdServ.bct[getBctClick().x + _bctClick.y * cmdServ.msz[0]];
                setNbrResPos(tempsbct);
            } else {
                std::cout << "Player on this case" << std::endl;
                textbox = false;
                playerInfo = true;
                
            }
        } else {
            textbox = false;
            return;
        }
    }
}

void Game::setNbrResPos(std::string tempsbct)
{
    square.setPosition(getBctClick().x * SIZE_BLOCK, _bctClick.y * SIZE_BLOCK);
    coo.setString("X: " + std::to_string(getBctClick().x) + " Y: " + std::to_string(_bctClick.y));
    std::stringstream ss(tempsbct);
    std::string ressourceCount;
    for (int count = 0; std::getline(ss, ressourceCount, ' '); count++) {
        if (count >= 2) {
            if (std::stoi(ressourceCount) > 99) {
                ressourceCount = "99+";
                nbrRes[count - 2].setPosition(_posTextbox.x + 30 + ((count - 2) * 100), _posTextbox.y + 50);
            } else if (std::stoi(ressourceCount) > 9) {
                nbrRes[count - 2].setPosition(_posTextbox.x + 40 + ((count - 2) * 100), _posTextbox.y + 50);
            } else {
                nbrRes[count - 2].setPosition(_posTextbox.x + 60 + ((count - 2) * 100), _posTextbox.y + 50);
            }
            nbrRes[count - 2].setString(ressourceCount);
        }
    }
}

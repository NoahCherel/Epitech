/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** teamsColor
*/

#ifndef TEAMSCOLOR_HPP_
#define TEAMSCOLOR_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

class TeamColor {
    public:
        TeamColor() = default;
        TeamColor(std::string teamName, sf::Color color, sf::Color revColor) : _teamName(teamName), _color(color), _revColor(revColor) {};
        ~TeamColor() = default;

        void setTeamName(std::string teamName) { _teamName = teamName; };
        void setColor(sf::Color color) { _color = color; };
        void setRevColor(sf::Color revColor) { _revColor = revColor; };
        void setTeamsColors(std::vector<TeamColor> teamsColors) { _teamsColors = teamsColors; };

        std::string getTeamName() const { return _teamName; };
        sf::Color getColor() const { return _color; };
        sf::Color getRevColor() const { return _revColor; };
        std::vector<TeamColor> getTeamsColors() const { return _teamsColors; };

        sf::Color createRandomColor();
        std::vector<TeamColor> createTeamsColors(std::vector<std::string> teamsNames);
    private:
        std::string _teamName;
        sf::Color _color;
        sf::Color _revColor;
        std::vector<TeamColor> _teamsColors;
};

#endif /* !TEAMSCOLOR_HPP_ */

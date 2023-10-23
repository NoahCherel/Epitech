/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** egg
*/

#ifndef EGG_HPP_

    #include <SFML/Graphics.hpp>
    #include <iostream>

    #include "teamsColor.hpp"
    #include "player.hpp"

    class Egg {
        public:
            Egg() = default;
            Egg(const std::vector<std::string>& enw);
            ~Egg() = default;

            void setEggId(int eggId) { _eggId = eggId; };
            void setPosX(int posX) { _posX = posX; };
            void setPosY(int posY) { _posY = posY; };
            void setTeamName(std::string team) { _team = team; };
            void setSprite(sf::Sprite sprite) { _sprite = sprite; };
            void setTexture(sf::Texture texture) { _texture = texture; };

            int getEggId() const { return _eggId; };
            int getPosX() const { return _posX; };
            int getPosY() const { return _posY; };
            std::string getTeamName() const { return _team; };
            sf::Sprite getSprite() const { return _sprite; };
            sf::Texture getTexture() const { return _texture; };

            void processNewEgg(const std::vector<std::string>& enw, const std::vector<TeamColor>& teamsColors, std::vector<Egg>& eggs, std::vector<Player>& players,std::vector<std::vector<sf::Texture>>& textures);
        private:
            int _eggId;
            int _posX;
            int _posY;
            std::string _team;
            sf::Texture _texture;
            sf::Sprite _sprite;
    };

#define EGG_HPP_


#endif /* !EGG_HPP_ */

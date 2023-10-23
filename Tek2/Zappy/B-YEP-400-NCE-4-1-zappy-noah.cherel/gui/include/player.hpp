/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <SFML/Graphics.hpp>
    #include <iostream>

    #include "teamsColor.hpp"

    class Player {
        public:
            Player() = default;
            Player(const std::vector<std::string>& pnw);
            Player(int id, int posX, int posY, int orientation, int level, std::string team) : _id(id), _posX(posX), _posY(posY), _orientation(orientation), _level(level), _team(team) {};
            ~Player() = default;

            void setPosX(int posX) { _posX = posX; };
            void setPosY(int posY) { _posY = posY; };
            void setOrientation(int orientation) { _orientation = orientation; };
            void setLevel(int level) { _level = level; };
            void setTeamName(std::string team) { _team = team; };
            void setId(int id) { _id = id; };
            void setSprite(sf::Sprite sprite) { _sprite = sprite; };
            void setTexture(sf::Texture texture) { _texture = texture; };
            void setFood(int food) { _food = food; };
            void setLinemate(int linemate) { _linemate = linemate; };
            void setDeraumere(int deraumere) { _deraumere = deraumere; };
            void setSibur(int sibur) { _sibur = sibur; };
            void setMendiane(int mendiane) { _mendiane = mendiane; };
            void setPhiras(int phiras) { _phiras = phiras; };
            void setThystame(int thystame) { _thystame = thystame; };
            void setBroadcast(int broadcast) { _broadcast = broadcast; };
            void setIsBroadcasting(bool isBroadcasting) { _isBroadcasting = isBroadcasting; };

            int getId() const { return _id; };
            int getPosX() const { return _posX; };
            int getPosY() const { return _posY; };
            int getOrientation() const { return _orientation; };
            int getLevel() const { return _level; };
            std::string getTeamName() const { return _team; };
            sf::Sprite getSprite() const { return _sprite; };
            sf::Texture getTexture() const { return _texture; };
            int getFood() const { return _food; };
            int getLinemate() const { return _linemate; };
            int getDeraumere() const { return _deraumere; };
            int getSibur() const { return _sibur; };
            int getMendiane() const { return _mendiane; };
            int getPhiras() const { return _phiras; };
            int getThystame() const { return _thystame; };
            int getBroadcast() const { return _broadcast; };
            bool getIsBroadcasting() const { return _isBroadcasting; };

            void processNewPlayer(const std::vector<std::string>& pnw, const std::vector<TeamColor>& teamsColors, std::vector<Player>& players, std::vector<std::vector<sf::Texture>>& textures);
            void processPlayerPosition(const std::vector<std::string>& ppo, std::vector<Player>& players, const std::vector<TeamColor>& teamsColors, std::vector<std::vector<sf::Texture>>& textures);
            void processPlayerLevel(const std::vector<std::string>& plv, std::vector<Player>& players, const std::vector<TeamColor>& teamsColors, std::vector<std::vector<sf::Texture>>& textures);
            void processPlayerDrop(const std::vector<std::string>& pdr, std::vector<Player>& players);
            void processPlayerPickup(const std::vector<std::string>& pgt, std::vector<Player>& players);
            void processPlayerInventory(const std::vector<std::string>& pin, std::vector<Player>& players);
            void processPlayerDeath(std::string& pdi, std::vector<Player>& players);
            void processPlayerBroadcast(const std::vector<std::string>& pbc, std::vector<Player>& players);

            void setPlayerColors(const std::vector<TeamColor>& teamsColors, Player& player, sf::Color& color, sf::Color& revColor);
            sf::Sprite createSpriteFromTexture(sf::Texture& texture, int orientation, int level, int posX, int posY);
            void printPlayer(const Player& player);
            void printAllPlayers(const std::vector<Player>& players);

        private:
            int _id;
            int _posX;
            int _posY;
            int _orientation;
            int _level;
            std::string _team;
            sf::Texture _texture;
            sf::Sprite _sprite;
            int _food;
            int _linemate;
            int _deraumere;
            int _sibur;
            int _mendiane;
            int _phiras;
            int _thystame;
            int _broadcast;
            bool _isBroadcasting;
    };

#endif /* !PLAYER_HPP_ */

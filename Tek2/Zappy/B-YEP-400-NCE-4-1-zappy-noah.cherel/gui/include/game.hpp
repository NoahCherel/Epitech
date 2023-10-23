/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <random>
#include <cstdint>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <list>
#include <chrono>
#include <cmath>

#include "player.hpp"
#include "teamsColor.hpp"
#include "egg.hpp"
#define SIZE_BLOCK 96

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct CommandServer {
    std::vector<int> msz;
    int sgt;
    std::vector<std::string> bct;
    std::vector<std::string> tna;
    std::vector<std::string> pnw;
    std::vector<std::string> ppo;
    std::vector<std::string> plv;
    std::vector<std::string> teamName;
    std::vector <std::string> pdi;
    std::vector<std::string> pin;
    std::vector<std::string> pdr;
    std::vector<std::string> pgt;
    std::vector<std::string> enw;
    std::vector<std::string> pbc;
};

struct Utils {
    static std::vector<std::vector<int>> convertStringVectorTo2DIntVector(const std::vector<std::string>& stringVector);
    static std::vector<std::vector<std::vector<std::vector<int>>>> addRandomValue(int sizeX, int sizeY, int sizeZ);
    static std::vector<int> createRandomList(int size, int max);
    static std::vector<std::vector<std::string>> divideVector(const std::vector<std::string>& vector, int size);
    static void modifyImagePixels(sf::Image& image, const sf::Color& green, const sf::Color& red, const sf::Color& color, const sf::Color& revColor);
    static sf::RectangleShape setRectangle(sf::RectangleShape rectangle, sf::Vector2f pos, sf::Vector2f size, sf::Color color, int fillColor);
    static sf::SoundBuffer setSoundBuffer(sf::SoundBuffer soundBuffer, std::string path);

};

class Server_info {
    public:
        void setSock(int sock) { _sock = sock; };
        void setServerName(std::string serverName) { _serverName = serverName; };
        void setServerPort(int serverPort) { _serverPort = serverPort; };

        int getSock() const { return _sock; };
        std::string getServerName() const { return _serverName; };
        int getServerPort() const { return _serverPort; };

        void sendCommand(int sock, const std::string& command);
        std::string receiveResponse(int sock);
        int servConnection(std::string serverIP, int serverPort);
        CommandServer affectedValue(std::string str, CommandServer cmdServ);
        CommandServer updateBct(CommandServer cmdServ);
        CommandServer getCmdServ();
    private:
        int _sock;
        std::string _serverName;
        int _serverPort;
};

class Game {
    public:

        Game();
        void init();

        void setCubeIndices(std::vector<int> cubeIndices) { _cubeIndices = cubeIndices; };
        void setWaterIndices(std::vector<int> waterIndices) { _waterIndices = waterIndices; };
        void setCameraPosition(sf::Vector2f cameraPosition) { this->_cameraPosition = cameraPosition; };
        void setCameraSpeed(float cameraSpeed) { this->_cameraSpeed = cameraSpeed; };
        void setPlayers(std::vector<Player> players) { _players = players; };
        void setPosResource(std::vector<std::vector<std::vector<std::vector<int>>>> PosResource) { this->_PosResource = PosResource; };
        void setPosTextbox(sf::Vector2f posTextbox) { this->_posTextbox = posTextbox; };
        void setCoo(sf::Text coo) { this->coo = coo; };
        void setBctClick(sf::Vector2i bctClick) { this->_bctClick = bctClick; };

        std::vector<int> getCubeIndices() const { return _cubeIndices; };
        std::vector<int> getWaterIndices() const { return _waterIndices; };
        sf::Vector2f getCameraPosition() const { return _cameraPosition; };
        float getCameraSpeed() const { return _cameraSpeed; };
        std::vector<Player> getPlayers() const { return _players; };
        std::vector<std::vector<std::vector<std::vector<int>>>> getPosResource() const { return _PosResource; };
        std::string getImageBlockPath() const { return imageBlockPath; };
        sf::Vector2f getPosTextbox() const { return _posTextbox; };
        sf::Text getCoo() const { return coo; };
        sf::Vector2i getBctClick() const { return _bctClick; };

        void game(unsigned int w, unsigned int h, const std::string& title, Server_info server, CommandServer cmdServ);
        void processEvents(sf::RenderWindow& window, CommandServer cmdServ);
        void renderSprites(sf::RenderWindow& window, const std::vector<sf::Sprite>& sprites, const std::vector<sf::Sprite>& sprite2, const sf::Sprite sprite3);
        void moveCamera(const Direction& direction, CommandServer cmdServ);
        void initializeMap(CommandServer cmdServ);

        std::vector<sf::Sprite> createWaterCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock);
        std::vector<sf::Sprite> createTerrainCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock);
        sf::Sprite createTextbar(const sf::Texture& HotbarTexture, CommandServer cmdServ, sf::Vector2f rect, sf::Vector2f scale);
        sf::Text setText(const sf::Font& font, std::string text, sf::Vector2f pos, int size, sf::Color color);

        sf::Texture loadTexture(const std::string& imageBlockPath);
        std::vector<sf::Sprite> createCubes(const sf::Texture& blockTexture, int sizeX, int sizeY, int sizeBlock);

        std::vector<sf::Sprite> createResource(const sf::Texture& blockTexture, std::vector<std::string> bct, std::vector<std::vector<std::vector<std::vector<int>>>> PosResource);
        std::vector<sf::Sprite> updateResources(const sf::Texture& blockTexture, std::vector<sf::Sprite>& sprites, std::vector<std::vector<int>> intMatrix);

        std::vector<std::vector<sf::Texture>> createTeamsTextures(const std::vector<TeamColor>& teamsColors);
        void setGame(CommandServer cmdServ);
        void setNbrResPos(std::string tempsbct);

        void eventR();
        void eventT(CommandServer cmdServ);
        void eventU(CommandServer cmdServ);
        void eventMouseClickLeft(CommandServer cmdServ, sf::Event event);
    private:
        std::vector<int> _cubeIndices;
        std::vector<int> _waterIndices;
        sf::Vector2f _cameraPosition;
        float _cameraSpeed;
        std::vector<Player> _players;
        std::vector<Egg> _eggs;
        std::vector<std::vector<std::vector<std::vector<int>>>> _PosResource;
        bool textbox = false;
        bool teamsInfo = false;
        bool playerInfo = false;
        sf::Vector2f _posTextbox;
        sf::Vector2i _bctClick;

        std::string imageBlockPath = "gui/assets/spritesheet.png";
        std::string imageHotBar = "gui/assets/hotbar.png";
        sf::SoundBuffer _levelUp;
        sf::Sound _levelUpSound;
        sf::SoundBuffer _suuu;
        sf ::Sound _suuuSound;
        sf::SoundBuffer _death;
        sf::Sound _deathSound;

        sf::Font font;
        sf::Text coo;
        sf::Text lvlPlayer;
        sf::Text nameTeamPlayer;
        sf::Text nameTeam;
        sf::Text infoPlayerTeam[8];
        sf::Text nbrRes[7];
        sf::Text invPlayer[7];
        sf::RectangleShape square;
        int nbrTeam = -1;
        int idSelectPlayer = -1;
        std::string tempsbct;
        std::string tempInv;

        sf::Texture hotBarTexture;
        sf::Texture blockTexture;
        sf::Texture playerTexture;
        sf::Sprite hotbar;
        std::vector<sf::Sprite> sprite;
        std::vector<sf::Sprite> cubes;
        sf::Vector2f windowSz;
        sf::Vector2f mapSz;
        std::vector<std::vector<sf::Texture>> TeamsTextures;

        sf::Vector2f _posClick;

        sf::Sprite communication;
        std::vector<sf::Sprite> communicationSprite;

       sf::Sprite water;
       std::vector<sf::Sprite> waterCubes;
       sf::IntRect sourceRectWater;

        float rotation = 1;
        bool upRotate = true;
        float rotationSpeed = 0.25;
        sf::Time deltaTime;
        float dt;
    };


class Resources {
    public:
        void displayBct(std::vector<std::string> bct);
};

#endif /* !GAME_HPP_ */

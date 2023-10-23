/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** game.cpp
*/

#include "../include/game.hpp"
#include "../include/player.hpp"

#define Keyb sf::Keyboard
Utils utils;

Game::Game()
{
    init();
}

void Game::init()
{
    setCameraSpeed(24);
}

bool comparePlayers(const Player& player1, const Player& player2) {
    return player1.getPosY() < player2.getPosY();
}

void Game::moveCamera(const Direction& direction, CommandServer cmdServ)
{
    switch (direction) {
        case Direction::UP:
            if (getCameraPosition().y - getCameraSpeed() >= -(SIZE_BLOCK * 5)) {
                setCameraPosition(sf::Vector2f(getCameraPosition().x, getCameraPosition().y -(getCameraSpeed())));
                _posTextbox.y -= getCameraSpeed();
            }
            break;
        case Direction::DOWN:
            if (getCameraPosition().y + getCameraSpeed() <= SIZE_BLOCK * cmdServ.msz[1] + SIZE_BLOCK * 5 - 1080) {
                setCameraPosition(sf::Vector2f(getCameraPosition().x, getCameraPosition().y +(getCameraSpeed())));
                _posTextbox.y += getCameraSpeed();
            }
            break;
        case Direction::LEFT:
            if (getCameraPosition().x - getCameraSpeed() >= -(SIZE_BLOCK * 5)) {
                setCameraPosition(sf::Vector2f(getCameraPosition().x -(getCameraSpeed()), getCameraPosition().y));
                _posTextbox.x -= getCameraSpeed();
            }
            break;
        case Direction::RIGHT:
            if (getCameraPosition().x + getCameraSpeed() <= SIZE_BLOCK * cmdServ.msz[0] + SIZE_BLOCK * 5 - 1920) {
                setCameraPosition(sf::Vector2f(getCameraPosition().x +(getCameraSpeed()), getCameraPosition().y));
                _posTextbox.x += getCameraSpeed();
            }
            break;
        default:
            break;
    }
}

void Game::processEvents(sf::RenderWindow& window, CommandServer cmdServ)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                case sf::Keyboard::Z:
                    moveCamera(Direction::UP, cmdServ);
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    moveCamera(Direction::DOWN, cmdServ);
                    break;
                case sf::Keyboard::Left:
                case sf::Keyboard::Q:
                    moveCamera(Direction::LEFT, cmdServ);
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    moveCamera(Direction::RIGHT, cmdServ);
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::R:
                    eventR();
                    break;
                case sf::Keyboard::T:
                    eventT(cmdServ);
                    break;
                case sf::Keyboard::U:
                    eventU(cmdServ);
                    break;
                default:
                    break;
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            eventMouseClickLeft(cmdServ, event);
        }
    }
}

void Game::renderSprites(sf::RenderWindow& window, const std::vector<sf::Sprite>& sprites, const std::vector<sf::Sprite>& sprite2, const sf::Sprite sprite3)
{
    window.clear(sf::Color::White);
    sf::View view = window.getDefaultView();
    view.move(getCameraPosition()); // Apply camera translation
    window.setView(view);

    for (const auto& sprite : sprites)
    {
        window.draw(sprite);
    }
    if (textbox == true || playerInfo == true)
        window.draw(square);
    if (teamsInfo == true) {
        window.draw(nameTeam);
        for (int i = 0; i < 8; i++) {
            window.draw(infoPlayerTeam[i]);
        }
    }
    for (const auto& egg : _eggs)
    {
        sf::Sprite eggSprite = egg.getSprite();
        eggSprite.setTextureRect(sf::IntRect(128, 160, 32, 32));
        eggSprite.setScale(3, 3);
        eggSprite.setPosition(egg.getPosX() * SIZE_BLOCK, egg.getPosY() * SIZE_BLOCK);
        window.draw(eggSprite);
    }
    for (const auto& sprite2 : sprite2)
    {
        window.draw(sprite2);
    }
    for (const auto& player : _players)
    {
        window.draw(player.getSprite());
    }
    if (textbox == true) {
        window.draw(sprite3);
        window.draw(getCoo());
        for (int i = 0; i < 7; i++) {
            window.draw(nbrRes[i]);
        }
    }
    if (playerInfo == true) {
        window.draw(getCoo());
        window.draw(lvlPlayer);
        window.draw(nameTeamPlayer);
        window.draw(sprite3);
        for (int i = 0; i < 7; i++) {
            window.draw(invPlayer[i]);
        }
    }
    for (const auto& communicationSprite : communicationSprite)
    {
        window.draw(communicationSprite);
    }
    window.display();
}

std::vector<std::vector<sf::Texture>> Game::createTeamsTextures(const std::vector<TeamColor>& teamsColors)
{
    std::vector<std::vector<sf::Texture>> teamsTextures;
    for (std::size_t i = 0; i < teamsColors.size(); i++) {
        std::vector<sf::Texture> textureVector;
        sf::Texture playerTexture;
        sf::Texture eggTexture;
        playerTexture.loadFromFile("gui/assets/character.png");
        eggTexture.loadFromFile("gui/assets/spritesheet.png");
        sf::Image imagePlayer = playerTexture.copyToImage();
        utils.modifyImagePixels(imagePlayer, sf::Color::Green, sf::Color::Red, teamsColors[i].getColor(), teamsColors[i].getRevColor());
        playerTexture.loadFromImage(imagePlayer);
        sf::Image imageEgg = eggTexture.copyToImage();
        utils.modifyImagePixels(imageEgg, sf::Color::Green, sf::Color::Red, teamsColors[i].getColor(), teamsColors[i].getRevColor());
        eggTexture.loadFromImage(imageEgg);
        textureVector.push_back(playerTexture);
        textureVector.push_back(eggTexture);
        teamsTextures.push_back(textureVector);
    }
    return teamsTextures;
}

void Game::setGame(CommandServer cmdServ)
{
    setPosResource(utils.addRandomValue(cmdServ.msz[0], cmdServ.msz[1], 7));
    font.loadFromFile("gui/assets/minecraft_font.ttf");
    coo = setText(font, "X: 0 Y: 0", sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
    lvlPlayer = setText(font, "Level: 0", sf::Vector2f(0, 50), 40, sf::Color(255, 255, 255));
    nameTeamPlayer = setText(font, "Team: ", sf::Vector2f(0, 100), 40, sf::Color(255, 255, 255));
    nameTeam = setText(font, "Team: ", sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
    for (int i = 0; i < 7; i++) {
        nbrRes[i] = setText(font, "0", sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
        nbrRes[i].setPosition(_posTextbox.x + 60 + (i * 100), _posTextbox.y + 50);
    }
    for (int i = 0; i < 8; i++) {
        infoPlayerTeam[i] = setText(font, "0", sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
        infoPlayerTeam[i].setPosition(_posTextbox.x + 60 + (i * 100), _posTextbox.y + 50);
    }
    square = utils.setRectangle(square, sf::Vector2f(0, 0), sf::Vector2f(SIZE_BLOCK, SIZE_BLOCK), sf::Color::Cyan, 75);
    hotBarTexture = loadTexture(imageHotBar);
    blockTexture = loadTexture(imageBlockPath);
    playerTexture.loadFromFile("gui/assets/character.png");
    sf::IntRect test(0, 160, 32, 32); // (left, top, width, height)
    sourceRectWater = test;
    initializeMap(cmdServ);
    hotbar = createTextbar(hotBarTexture, cmdServ, sf::Vector2f(280, 40), sf::Vector2f(2.5, 2.5));
    sprite = createResource(blockTexture, cmdServ.bct, getPosResource());
    cubes = createCubes(blockTexture, cmdServ.msz[0], cmdServ.msz[1], SIZE_BLOCK);
    mapSz = sf::Vector2f(cmdServ.msz[0] * SIZE_BLOCK, cmdServ.msz[1] * SIZE_BLOCK); // Get the size of the map (in pixels)

    _levelUp = utils.setSoundBuffer(_levelUp, "gui/assets/Levelup.ogg");
    _levelUpSound.setBuffer(_levelUp);
    _suuu = utils.setSoundBuffer(_suuu, "gui/assets/Suuu.ogg");
    _suuuSound.setBuffer(_suuu);
    _death = utils.setSoundBuffer(_death, "gui/assets/Death.ogg");
    _deathSound.setBuffer(_death);

    setCameraPosition(sf::Vector2f((mapSz.x - windowSz.x) / 2.0f, (mapSz.y - windowSz.y) / 2.0f)); // Center the view on the map by default
    if (mapSz.x >= windowSz.x) { // If the map is bigger than the X screen size, set the viewX to the left of the map
        setCameraPosition(sf::Vector2f(getCameraPosition().x -(getCameraSpeed()), getCameraPosition().y));
    }
    if (mapSz.y >= windowSz.y) { // If the map is bigger than the Y screen size, set the viewY to the top of the map
        setCameraPosition(sf::Vector2f(getCameraPosition().x, getCameraPosition().y -(getCameraSpeed())));
    }
}

void Game::game(unsigned int w, unsigned int h, const std::string& title, Server_info server, CommandServer cmdServ)
{
    sf::RenderWindow window(sf::VideoMode(w, h), title);
    windowSz = sf::Vector2f(static_cast<float>(w), static_cast<float>(h - 64)); // Get the size of the game window
    setGame(cmdServ);

    TeamColor tCFunc;
    tCFunc.setTeamsColors(tCFunc.createTeamsColors(cmdServ.tna));
    TeamsTextures = createTeamsTextures(tCFunc.getTeamsColors());
    std::cout << "Team color:\n";
    for (std::size_t i = 0; i < tCFunc.getTeamsColors().size(); i++) {
        std::cout << " - " << tCFunc.getTeamsColors()[i].getTeamName() << " : base color ("
        << static_cast<int>(tCFunc.getTeamsColors()[i].getColor().r) << ", " << static_cast<int>(tCFunc.getTeamsColors()[i].getColor().g) << ", " << static_cast<int>(tCFunc.getTeamsColors()[i].getColor().b) << ") / rev color ("
        << static_cast<int>(tCFunc.getTeamsColors()[i].getRevColor().r) << ", " << static_cast<int>(tCFunc.getTeamsColors()[i].getRevColor().g) << ", " << static_cast<int>(tCFunc.getTeamsColors()[i].getRevColor().b) << ")\n";
        cmdServ.teamName.push_back(tCFunc.getTeamsColors()[i].getTeamName());
    } std::cout << std::endl;

    Player pFunc;
    Egg eFunc;

    float frameRate = 0.1f;
    float frameRateBroadcast = 0.7f;
    sf::Clock clock;
    float elapsedTime = 0.0f;
    float elapsedTimeBroadcast = 0.0f;

    sf::Texture texture;
    if (!texture.loadFromFile("gui/assets/spritesheet.png")) {
        std::cout << "Error loading spritesheet.png" << std::endl;
    }
    communication.setTexture(texture);
    water.setTexture(texture);
    sf::IntRect sourceRect(32, 32, 32, 32); // (left, top, width, height)

    while (window.isOpen())
    {
        deltaTime = clock.restart();
        dt = deltaTime.asSeconds();
        elapsedTime += dt;
        elapsedTimeBroadcast += dt;

        if (elapsedTimeBroadcast >= frameRateBroadcast) {
            if (sourceRect.left == 128) {
                sourceRect.left = 32;
            } else {
                    sourceRect.left += 32;
            }
            if (sourceRectWater.left == 96) {

                sourceRectWater.left = 0;
            } else {
                sourceRectWater.left += 32;
            }
            elapsedTimeBroadcast = 0.0f;
        }

        if (elapsedTime >= frameRate) {
            if (upRotate == true) {
                rotation += rotationSpeed;
                if (rotation >= 1) {
                    upRotate = false;
                } else if (rotation == 0) {
                    rotation += rotationSpeed;
                }
            } else {
                rotation -= rotationSpeed;
                if (rotation <= -1) {
                    upRotate = true;
                } else if (rotation == 0) {
                    rotation -= rotationSpeed;
                }
            }
            elapsedTime = 0.0f;
        }

        processEvents(window, cmdServ);

        if (cmdServ.pnw.size() > 0) {
            std::vector<std::vector<std::string>> pnwDivide = utils.divideVector(cmdServ.pnw, 6);
            for (std::size_t i = 0; i < pnwDivide.size(); i++) {
                std::cout << "New player connected :\n - Player Id(" << pnwDivide[i][0] << ") at (" << pnwDivide[i][1] << ", " << pnwDivide[i][2] << ") with orientation " << pnwDivide[i][3] << ", level " << pnwDivide[i][4] << " and team name \"" << pnwDivide[i][5] << "\"" << std::endl;
                pFunc.processNewPlayer(pnwDivide[i], tCFunc.getTeamsColors(), _players, TeamsTextures);
                std::cout << pFunc.getTeamName() << std::endl;
            }
            pFunc.printAllPlayers(_players);
            cmdServ.pnw.clear();
        }

        if (cmdServ.pdi.size() > 0) {
            for (std::size_t i = 0; i < cmdServ.pdi.size(); i++) {
                std::cout << "Player " << cmdServ.pdi[i] << " died" << std::endl;
                _deathSound.play();
                try {
                    std::cout << idSelectPlayer << " " << std::stoi(cmdServ.pdi[i]) << std::endl;
                    if (idSelectPlayer == std::stoi(cmdServ.pdi[i])) {
                        idSelectPlayer = -1;
                        playerInfo = false;
                    }
                } catch (std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                pFunc.processPlayerDeath(cmdServ.pdi[i], _players);
            }
            cmdServ.pdi.clear();
        }

        if (cmdServ.ppo.size() > 0) {
            std::vector<std::vector<std::string>> ppoDivide = utils.divideVector(cmdServ.ppo, 4);
            for (std::size_t i = 0; i < ppoDivide.size(); i++) {
                std::cout << "Player " << ppoDivide[i][0] << " moved to (" << ppoDivide[i][1] << ", " << ppoDivide[i][2] << ") with orientation " << ppoDivide[i][3] << std::endl;
                pFunc.processPlayerPosition(ppoDivide[i], _players, tCFunc.getTeamsColors(), TeamsTextures);
            }
            cmdServ.ppo.clear();
        }

        if (cmdServ.plv.size() > 0) {
            std::vector<std::vector<std::string>> plvDivide = utils.divideVector(cmdServ.plv, 2);
            for (std::size_t i = 0; i < plvDivide.size(); i++) {
                std::cout << "Player " << plvDivide[i][0] << " level up to " << plvDivide[i][1] << std::endl;
                atoi(plvDivide[i][1].c_str()) != 7 ? _levelUpSound.play() : _suuuSound.play();
                pFunc.processPlayerLevel(plvDivide[i], _players, tCFunc.getTeamsColors(), TeamsTextures);
            }
            cmdServ.plv.clear();
        }

        if (cmdServ.pdr.size() > 0) {
            std::vector<std::vector<std::string>> pdrDivide = utils.divideVector(cmdServ.pdr, 2);
            for (std::size_t i = 0; i < pdrDivide.size(); i++) {
                std::cout << "Player " << pdrDivide[i][0] << " dropped ressource " << pdrDivide[i][1] << std::endl;
                pFunc.processPlayerDrop(pdrDivide[i], _players);
            }
            cmdServ.pdr.clear();
        }

        if (cmdServ.pgt.size() > 0) {
            std::vector<std::vector<std::string>> pgtDivide = utils.divideVector(cmdServ.pgt, 2);
            for (std::size_t i = 0; i < pgtDivide.size(); i++) {
                std::cout << "Player " << pgtDivide[i][0] << " picked up ressource " << pgtDivide[i][1] << std::endl;
                pFunc.processPlayerPickup(pgtDivide[i], _players);
            }
            cmdServ.pgt.clear();
        }

        if (cmdServ.pin.size() > 0) {
            std::vector<std::vector<std::string>> pinDivide = utils.divideVector(cmdServ.pin, 10);
            for (std::size_t i = 0; i < pinDivide.size(); i++) {
                std::cout << "Player " << pinDivide[i][0] << " inventory : (" << pinDivide[i][3] << ", " << pinDivide[i][4] << ", " << pinDivide[i][5] << ", " << pinDivide[i][6] << ", " << pinDivide[i][7] << ", " << pinDivide[i][8] << ", " << pinDivide[i][9] << ")" << std::endl;
                pFunc.processPlayerInventory(pinDivide[i], _players);
            }
            cmdServ.pin.clear();
        }

        if (cmdServ.pbc.size() > 0) {
            std::vector<std::vector<std::string>> pbcDivide = utils.divideVector(cmdServ.pbc, 2);
            for (std::size_t i = 0; i < pbcDivide.size(); i++) {
                std::cout << "Player " << pbcDivide[i][0] << " broadcasted " << pbcDivide[i][1] << std::endl;
                pFunc.processPlayerBroadcast(pbcDivide[i], _players);
            }
            cmdServ.pbc.clear();
        }

        if (cmdServ.enw.size() > 0) {
            std::vector<std::vector<std::string>> enwDivide = utils.divideVector(cmdServ.enw, 4);
            for (std::size_t i = 0; i < enwDivide.size(); i++) {
                std::cout << enwDivide.size() << " " << i << std::endl;
                std::cout << "Egg " << enwDivide[i][0] << " created by player " << enwDivide[i][1] << " at (" << enwDivide[i][2] << ", " << enwDivide[i][3] << ")" << std::endl;
                eFunc.processNewEgg(enwDivide[i], tCFunc.getTeamsColors(), _eggs, _players, TeamsTextures);
                std::cout << "Egg team name: " << eFunc.getTeamName() << std::endl;
            }
            std::cout << "Eggs :\n";
            cmdServ.enw.clear();
            std::cout << "Eggs clear" << std::endl;
        }

        for (int i = 0; i < 8; i++) {
            infoPlayerTeam[i].setString("0");
        }
        for (std::size_t i = 0; i < _players.size(); i++) {
            try {
                if (cmdServ.teamName[nbrTeam] == _players[i].getTeamName()) {
                    infoPlayerTeam[_players[i].getLevel() - 1].setString(std::to_string(std::stoi(infoPlayerTeam[_players[i].getLevel() - 1].getString().toAnsiString()) + 1));
                }
                if (idSelectPlayer != -1) {
                    if (idSelectPlayer == _players[i].getId()) {
                        coo.setString("X: " + std::to_string(_players[i].getPosX()) + " Y: " + std::to_string(_players[i].getPosY()));
                        square.setPosition(_players[i].getPosX() * SIZE_BLOCK, _players[i].getPosY() * SIZE_BLOCK);
                        lvlPlayer.setString("Level: " + std::to_string(_players[i].getLevel()));
                        nameTeamPlayer.setString("Team: " + _players[i].getTeamName());
                        lvlPlayer.setPosition(getCameraPosition().x, getCameraPosition().y + 50);
                        nameTeamPlayer.setPosition(getCameraPosition().x, getCameraPosition().y + 100);
                        invPlayer[0] = setText(font, std::to_string(_players[i].getFood()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[1] = setText(font, std::to_string(_players[i].getLinemate()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[2] = setText(font, std::to_string(_players[i].getDeraumere()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[3] = setText(font, std::to_string(_players[i].getSibur()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[4] = setText(font, std::to_string(_players[i].getMendiane()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[5] = setText(font, std::to_string(_players[i].getPhiras()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        invPlayer[6] = setText(font, std::to_string(_players[i].getThystame()), sf::Vector2f(0, 0), 40, sf::Color(255, 255, 255));
                        for (int i = 0; i < 7; i++) {
                            invPlayer[i].setPosition(_posTextbox.x + 60 + (i * 100), _posTextbox.y + 50);
                            int ressourceCount = std::stoi(invPlayer[i].getString().toAnsiString());
                            if (ressourceCount > 99) {
                                invPlayer[i].setPosition(_posTextbox.x + 30 + (i * 100), _posTextbox.y + 50);
                            } else if (ressourceCount > 9) {
                                invPlayer[i].setPosition(_posTextbox.x + 40 + (i * 100), _posTextbox.y + 50);
                            } else {
                                invPlayer[i].setPosition(_posTextbox.x + 60 + (i * 100), _posTextbox.y + 50);
                            }
                        }
                    }
                }
                if (_players[i].getBroadcast() > 0) {
                    _players[i].setIsBroadcasting(true);
                    communication.setTextureRect(sourceRect);
                    communication.setScale(sf::Vector2f(2.5, 2.5));
                    communication.setPosition(_players[i].getPosX() * SIZE_BLOCK + 32, _players[i].getPosY() * SIZE_BLOCK - 96);
                    communicationSprite.push_back(communication);
                } else {
                    _players[i].setIsBroadcasting(false);
                    _players[i].setBroadcast(0);
                }
            } catch (std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        cmdServ.pnw.clear();
        cmdServ = server.updateBct(cmdServ);
        sprite = updateResources(blockTexture, sprite, utils.convertStringVectorTo2DIntVector(cmdServ.bct));

        hotbar.setPosition(_posTextbox.x, _posTextbox.y);
        coo.setPosition(getCameraPosition().x, getCameraPosition().y);
        nameTeam.setPosition(getCameraPosition().x, getCameraPosition().y);

        if (textbox == true) {
            tempsbct = cmdServ.bct[getBctClick().x + _bctClick.y * cmdServ.msz[0]];
            setNbrResPos(tempsbct);
        }
        for (int i = 0; i < 8; i++) {
            infoPlayerTeam[i].setPosition(getCameraPosition().x + (i * 50), getCameraPosition().y + 50);
        }
        std::sort(_players.begin(), _players.end(), comparePlayers);
        renderSprites(window, cubes, sprite, hotbar);
        communicationSprite.clear();
        waterCubes.clear();
    }
}

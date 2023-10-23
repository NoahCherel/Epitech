/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../include/core.hpp"
#include "../include/lib.hpp"
#include "../../interfaces/IGame.hpp"
#include "../../graphicals/ncurses/include/ncurses.hpp"


// lib order : ncurses, sfml, sdl2
void ArcadeCore::switchLib(int order, std::string lib)
{
    std::string currentLib = _libInstance->getName(), newLib = "";
    if (lib != "") {
        newLib = "lib/" + lib;
    } else {
        if (currentLib == "ncurses") {
            newLib = order ? "lib/arcade_sfml.so" : "lib/arcade_sdl2.so";
        } else if (currentLib == "sfml") {
            newLib = order ? "lib/arcade_sdl2.so" : "lib/arcade_ncurses.so";
        } else if (currentLib == "sdl2") {
            newLib = order ? "lib/arcade_ncurses.so" : "lib/arcade_sfml.so";
        }
    }
    _libInstance->stop(); _lib.closeLib();
    _lib.loadLib(newLib);
    if (!_lib.lib) {
        std::cerr << "Error: " << dlerror() << std::endl; return;
    }
    void *sym3 = dlsym(_lib.lib, "createLibrary");
    if (!sym3) {
        std::cerr << "Error: " << dlerror() << std::endl; return;
    }
    ILibrary *(*createLibrary)() = (ILibrary *(*)())sym3;
    _libInstance = createLibrary();
    _libInstance->init();
}

// game order : snake, nibbler
void ArcadeCore::switchGame(int order, std::string game)
{
    std::string currentGame = _gameInstance->getName(), newGame = "";
    if (game != "") {
        newGame = "lib/" + game;
    } else {
        if (currentGame == "snake") {
            newGame = order ? "lib/arcade_nibbler.so" : "lib/arcade_nibbler.so";
        } else if (currentGame == "nibbler") {
            newGame = order ? "lib/arcade_snake.so" : "lib/arcade_snake.so";
        } else {
            return;
        }
    }
    _gameInstance->stop(); _gamelib.closeLib();
    _gamelib.loadLib(newGame);
    if (!_gamelib.lib) {
        std::cerr << "Error: " << dlerror() << std::endl; return;
    }
    void *sym3 = dlsym(_gamelib.lib, "createGame");
    if (!sym3) {
        std::cerr << "Error: " << dlerror() << std::endl; return;
    }
    IGame *(*createGame)() = (IGame *(*)())sym3;
    _gameInstance = createGame();
    _gameInstance->init(); _gameName = _gameInstance->getName();
}

// format : {"LIB:[path]", "GAME:[path]"}
void ArcadeCore::loadLibAndGame(std::vector<std::string> hEventReturn)
{
    for (auto &it : hEventReturn) {
        if (it.find("LIB:") != std::string::npos) {
            if (it.substr(4) != "arcade_" + _libInstance->getName() + ".so") {
                switchLib(0, it.substr(4));
            }
        } else if (it.find("GAME:") != std::string::npos) {
            switchGame(0, it.substr(5));
        }
    }
}

int error_handling(int ac, char **av)
{
    if (ac != 2) {
        throw std::invalid_argument("Usage: ./arcade [lib.so]");
    }
    if (access(av[1], F_OK) == -1) {
        throw std::runtime_error(std::string("Error: ") + av[1] + " does not exist");
    }
    if (access(av[1], R_OK) == -1) {
        throw std::runtime_error(std::string("Error: ") + av[1] + " is not readable");
    }
    if (std::string(av[1]).find("arcade_ncurses.so") == std::string::npos
        && std::string(av[1]).find("arcade_sfml.so") == std::string::npos
        && std::string(av[1]).find("arcade_sdl2.so") == std::string::npos) {
        throw std::runtime_error(std::string("Error: ") + av[1] + " is not a valid library");
    }
    return 0;
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    ArcadeCore arcade;
    arcade.launchArcade(av[1]);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <iostream>
    #include <string>
    #include <vector>
    #include <dlfcn.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <algorithm>
    #include <memory>
    #include "./lib.hpp"
    #include "../../interfaces/ILibrary.hpp"
    #include "../../interfaces/IGame.hpp"

    #define SNAKE 1
    #define NIBBLER 2
    #define MENU 3

class ArcadeCore {
public:
    ArcadeCore(){}
    ~ArcadeCore(){}
    void help(){
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./arcade [lib.so]" << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tlib.so\t\tlibrary in which the game will be played" << std::endl;
    }
    void launchArcade(std::string libPath) {
        _lib.loadLib(libPath); _gamelib.loadLib("lib/arcade_menu.so");
        if (!_lib.lib || !_gamelib.lib) {
            std::cerr << "Error: " << dlerror() << std::endl;
            return;
        }
        void *sym = dlsym(_lib.lib, "createLibrary");
        void *sym2 = dlsym(_gamelib.lib, "createGame");
        if (!sym || !sym2) {
            std::cerr << "Error: " << dlerror() << std::endl;
            return;
        }
        ILibrary *(*createLibrary)() = (ILibrary *(*)())sym;
        _libInstance = createLibrary();
        IGame *(*createGame)() = (IGame *(*)())sym2;
        _gameInstance = createGame();
        std::string event = "";
        std::vector<std::string> map = _gameInstance->getMap();
        _libName = _libInstance->getName(), _gameName = _gameInstance->getName();
        std::vector<std::string> hEventReturn = {};
        _libInstance->display(map);
        while (true) {
            if (_gameInstance->getMap() != map || _libInstance->getName() != _libName) {
                map = _gameInstance->getMap();
                _libName = _libInstance->getName();
                _libInstance->clear();
                _libInstance->display(map);
            }
            event = _libInstance->getEvent();
            hEventReturn = _gameInstance->handleEvent(event);
            if (hEventReturn.size() > 0) loadLibAndGame(hEventReturn);
            if (event == "QUIT" || (event == "ESC" && _gameName == "menu")) break;
            if (event == "F1") switchLib(0, "");
            if (event == "F2") switchLib(1, "");
            if (event == "F3") switchGame(0, "");
            if (event == "F4") switchGame(1, "");
            if (!_gameInstance->isRunning()) switchGame(0, "arcade_menu.so");
        }
        _libInstance->stop(); _gameInstance->stop();
        _lib.closeLib(); _gamelib.closeLib();
    }
    void switchLib(int order, std::string lib);
    void switchGame(int order, std::string game);
    void loadLibAndGame(std::vector<std::string> hEventReturn);
    private:
        std::string _gameName;
        std::string _libName;
        Lib _lib;
        Lib _gamelib;
        ILibrary *_libInstance;
        IGame *_gameInstance;
};

#endif /* !CORE_HPP_ */

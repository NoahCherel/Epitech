/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../include/menu.hpp"
#include "../../../core/include/lib.hpp"
#include "../../../interfaces/ILibrary.hpp"
#include <iostream>
#include <filesystem>
#include <dlfcn.h>
#include <vector>
#include <dirent.h>
#include <string.h>

Menu::Menu() {
    init();
}

Menu::~Menu() {
    stop();
}

std::string Menu::getName() {
    return "menu";
}

std::vector<std::string> removeExtension(std::vector<std::string> vec)
{
    std::vector<std::string> newVec;
    for (std::string str : vec) {
        if (str.substr(0, 7) == "arcade_") {
            str = str.substr(7);
        }
        if (str.substr(str.size() - 3) == ".so") {
            str = str.substr(0, str.size() - 3);
        }
        newVec.push_back(str);
    }
    return newVec;
}

void Menu::getScore()
{
    std::ifstream file("best_score.txt");
    std::ifstream file2("new_score.txt");
    std::ifstream file3("best_name.txt");
    std::ifstream file4("new_name.txt");
    std::string str;
    int score = 0;
    int score2 = 0;
    std::string new_name = "";
    std::string best_name = "";
    if (file.is_open()) {
        while (getline(file, str)) {
            std::string::size_type pos = str.find('\n');
            if (pos != std::string::npos) {
                str = str.substr(0, pos);
            }
            score = std::stoi(str);
            break;
        }
        file.close();
    }
    if (file2.is_open()) {
        while (getline(file2, str)) {
            score2 = std::stoi(str);
        }
        file2.close();
    } else {
        std::ofstream file; file.open("new_score.txt"); file << "0"; file.close();
    }
    if (file3.is_open()) {
        while (getline(file3, str)) {
            best_name = str;
        }
        file3.close();
    } else {
        std::ofstream file; file.open("best_name.txt"); file << ""; file.close();
    }
    if (file4.is_open()) {
        while (getline(file4, str)) {
            new_name = str;
        }
        file4.close();
    } else {
        std::ofstream file; file.open("new_name.txt"); file << " "; file.close();
    }

    if (score2 > score) {
        _bestScore = score2;
        std::ofstream file; file.open("best_score.txt"); file << score2;
        std::ofstream file3; file3.open("best_name.txt"); file3 << new_name; file3.close();
        file.close();
    }
}

void Menu::init() {
    int width = 30, height = 21;
    _wall = "-----------------------------\n";
    for (int i = 0; i < height - 5; i++) {
        _wall += "|              |            |\n";
    }
    _wall += "-----------------------------\n";
    for (int i = 16; i < height - 1; i++) {
        _wall += "|                           |\n";
    }
    _wall += "-----------------------------\n";
    _isRunning = true; srand(time(NULL));
    _files = libFile();
    std::vector<std::string> libv = removeExtension(find_library(_files));
    std::vector<std::string> gamev = removeExtension(find_game(_files));
    int a = countVector(libv);
    int b = countVector(gamev);
    int libPos = width * 1 + 2;
    _map = _wall.substr(0, libPos) + ' ' + _wall.substr(libPos + 1);
    std::string lib = "LIBRARIES";
    std::string game = "GAMES";
    std::string name = "NAME:";
    getScore();

    std::ifstream file("best_name.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    std::ifstream file2("best_score.txt");
    std::stringstream buffer2;
    buffer2 << file2.rdbuf();
    std::string fileContent2 = buffer2.str();


    std::string score = "BEST SCORE:" + fileContent + " " + fileContent2;

    for (int x = 0; x < (int)lib.size(); x++) _map[libPos + x] = lib[x];
    for (int x = 0; x < (int)game.size(); x++) _map[libPos + x + width / 2] = game[x];
    for (int x = 0; x < (int)name.size(); x++) _map[30 * 18 + 2 + x] = name[x];
    for (int x = 0; x < (int)score.size(); x++) _map[30 * 20 + 2 + x] = score[x];
    for (int i = 0; i < a; i++) {
        int libPos = width * (i + 3) + 2;
        for (int x = 0; x < (int)libv[i].size(); x++) {
            _map[libPos + x] = libv[i][x];
        }
    }
    for (int i = 0; i < b; i++) {
        int gamePos = width * (i + 3) + 2 + width / 2;
        for (int x = 0; x < (int)gamev[i].size(); x++) {
            _map[gamePos + x] = gamev[i][x];
        }
    }
    _map[width * 3 + 1] = '>';
}

int Menu::countVector(std::vector<std::string> vec)
{
    int i = 0;
    for (std::string str : vec) {
        i++;
    }
    return i;
}

std::vector<std::string> Menu::libFile()
{
    std::vector<std::string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("lib/")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[strlen(ent->d_name)-1] == 'o' && ent->d_name[strlen(ent->d_name)-2] == 's' && ent->d_name[strlen(ent->d_name)-3] == '.')
            {
                files.push_back(ent->d_name);
            }
        }
        closedir(dir);
    }
    return files;
}

std::vector<std::string> Menu::find_library(std::vector<std::string> fichiers2)
{
    std::vector<std::string> libs;
    for (std::string fichier : fichiers2) {
        void* _lib = dlopen(("lib/" + fichier).c_str(), RTLD_LAZY);
        if (!_lib) {
            std::cerr << "Error: " << dlerror() << std::endl;
        }
        void* sym = dlsym(_lib, "createLibrary");
        if (sym) {
            libs.push_back(fichier);

        }
    }
    return libs;
}

std::vector<std::string> Menu::find_game(std::vector<std::string> fichiers2)
{
    std::vector<std::string> libs;
    for (std::string fichier : fichiers2) {
        void* _lib = dlopen(("lib/" + fichier).c_str(), RTLD_LAZY);
        if (!_lib) {
            std::cerr << "Error: " << dlerror() << std::endl;
        }
        void* sym = dlsym(_lib, "createGame");
        if (sym && fichier != "arcade_menu.so") {
            libs.push_back(fichier);
        }
    }
    return libs;
}

int Menu::stop() {
    _isRunning = false;
    return 0;
}

bool Menu::isRunning() {
    return _isRunning;
}

void Menu::endGame() {
    _isRunning = false;
}

std::vector<std::vector<int>> Menu::getSymbol(char c) {
    std::vector<std::vector<int>> symbols;
    int width = 30;
    for (int i = 0; i < (int)_map.size(); i++) {
        if (_map[i] == c) {
            std::vector<int> symbol;
            symbol.push_back(i % width);
            symbol.push_back(i / width);
            symbols.push_back(symbol);
        }
    }
    return symbols;
}

std::vector<std::string> Menu::handleEvent(std::string event) {
    std::vector<int> cursor = getSymbol('>').at(0);
    if (_isName == false) {
        if (event == "UP") {
            if (cursor[1] > 3) {
                _map[cursor[1] * 30 + cursor[0]] = ' ';
                _map[(cursor[1] - 1) * 30 + cursor[0]] = '>';
            }
        }
        if (event == "DOWN") {
            if (_map[(cursor[1] + 1) * 30 + cursor[0] + 1] != ' ') {
                _map[cursor[1] * 30 + cursor[0]] = ' ';
                _map[(cursor[1] + 1) * 30 + cursor[0]] = '>';
            }
        }
        if (event == "ENTER" || event == "SPACE") {
            if (cursor[0] == 1 && cursor[1] < 16) {
                _map[cursor[1] * 30 + cursor[0]] = '$';
                _map[30 * 3 + 16] = '>';
            } else if (cursor[0] == 16 && cursor[1] >= 3) {
                _map[18 * 30 + 1] = '>';
                _map[cursor[1] * 30 + cursor[0]] = '$';
                _isName = true;
            }
        }
    } else {
        if (event == "BACKSPACE" && countSpaceName > 0) {
            countSpaceName--;
            _name.pop_back();
            _map[30 * 18 + 7 + countSpaceName] = ' ';
        } else if (event == "ENTER" || event == "SPACE") {
            std::vector<std::vector<int>> coords;
            if (getSymbol('$').at(0)[0] == 1) {
                coords.push_back(getSymbol('$').at(0));
                coords.push_back(getSymbol('$').at(1));
            } else {
                coords.push_back(getSymbol('$').at(1));
                coords.push_back(getSymbol('$').at(0));
            }
            std::string lib = "LIB:" + find_library(_files)[coords.at(0)[1] - 3];
            std::string game = "GAME:" + find_game(_files)[coords.at(1)[1] - 3];
            _isName = false; countSpaceName = 0;
            return {lib, game};
        } else if (event.size() == 1 && countSpaceName <= 14) {
            _map[30 * 18 + 7 + countSpaceName] = event[0];
            _name += event[0];
            std::ofstream file; file.open("new_name.txt", std::ofstream::trunc); file << _name;
            countSpaceName++;
        }
    }
    return {};
}

std::vector<std::string> Menu::getMap() {
    std::vector<std::string> mapVector;
    std::istringstream iss(_map);
    std::string line;
    while (std::getline(iss, line, '\n')) {
        mapVector.push_back(line);
    }
    return mapVector;
}

extern "C" IGame *createGame() {
    return new Menu();
}

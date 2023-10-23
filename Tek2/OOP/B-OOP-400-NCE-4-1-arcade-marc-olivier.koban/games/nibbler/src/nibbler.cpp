/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../include/nibbler.hpp"

Nibbler::Nibbler() {
    //init();
}

Nibbler::~Nibbler() {
    stop();
}

std::string Nibbler::getName() {
    return "nibbler";
}

void Nibbler::init() {
    _map = ""; _nibblerBody.clear(); _direction = "LEFT";
    std::ifstream mapFile("games/nibbler/src/map.txt");
    if (!mapFile.is_open()) {
        std::cerr << "Error: could not open map file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(mapFile, line)) {
        _map += line + "\n";
    }
    mapFile.close();
    size_t nibblerPos = _map.find("$~~~");
    if (nibblerPos == std::string::npos) {
        std::cerr << "Error: could not find snake in map file" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        _nibblerBody.push_back(nibblerPos + i);
    }
    _isRunning = true;
}

int Nibbler::stop() {
    _isRunning = false;
    return _score;
}

void Nibbler::moveNibbler(std::string event) {
    int nextPos = -1; std::string oldDirection = _direction; std::string oldPremoveDirection = _premoveDirection;
    switch(event[0]) {
        case 'L': _premoveDirection = _direction == "RIGHT" ? "RIGHT" : "LEFT"; break;
        case 'R': _premoveDirection = _direction == "LEFT" ? "LEFT" : "RIGHT"; break;
        case 'U': _premoveDirection = _direction == "DOWN" ? "DOWN" : "UP"; break;
        case 'D': _premoveDirection = _direction == "UP" ? "UP" : "DOWN"; break;
        default: break;
    }
    if (_premoveDirection != "") {
        _direction = _premoveDirection;
    }
    bool canGoLeft = (_direction != "RIGHT" && (_nibblerBody.front() % 30 != 0) && _map[_nibblerBody.front() - 1] != '|' && std::find(_nibblerBody.begin(), _nibblerBody.end(), _nibblerBody.front() - 1) == _nibblerBody.end());
    bool canGoRight = (_direction != "LEFT" && ((_nibblerBody.front() + 1) % 30 != 0) && _map[_nibblerBody.front() + 1] != '|' && std::find(_nibblerBody.begin(), _nibblerBody.end(), _nibblerBody.front() + 1) == _nibblerBody.end());
    bool canGoUp = (_direction != "DOWN" && (_nibblerBody.front() >= 30) && _map[_nibblerBody.front() - 30] != '-' && std::find(_nibblerBody.begin(), _nibblerBody.end(), _nibblerBody.front() - 30) == _nibblerBody.end());
    bool canGoDown = (_direction != "UP" && (_nibblerBody.front() <= (int)_map.size() - 30 - 1) && _map[_nibblerBody.front() + 30] != '-' && std::find(_nibblerBody.begin(), _nibblerBody.end(), _nibblerBody.front() + 30) == _nibblerBody.end());
    if (!canGoLeft && !canGoRight && !canGoUp && !canGoDown) {
        _direction = oldDirection;
        return;
    }
    if (canGoLeft && !canGoRight && !canGoUp && !canGoDown) {
        _direction = "LEFT";
        test = 1;
    } else if (!canGoLeft && canGoRight && !canGoUp && !canGoDown) {
        _direction = "RIGHT";
        test = 2;
    } else if (!canGoLeft && !canGoRight && canGoUp && !canGoDown) {
        _direction = "UP";
        test = 3;
    } else if (!canGoLeft && !canGoRight && !canGoUp && canGoDown) {
        _direction = "DOWN";
        test = 4;
    }
    if (_premoveDirection == "LEFT" && test == 1) {
        _premoveDirection = "";
    } else if (_premoveDirection == "RIGHT" && test == 2) {
        _premoveDirection = "";
    } else if (_premoveDirection == "UP" && test == 3) {
        _premoveDirection = "";
    } else if (_premoveDirection == "DOWN" && test == 4) {
        _premoveDirection = "";
    }
    if (_direction == "LEFT") {
        nextPos = _nibblerBody.front() - 1;
    } else if (_direction == "RIGHT") {
        nextPos = _nibblerBody.front() + 1;
    } else if (_direction == "UP") {
        nextPos = _nibblerBody.front() - 30;
    } else if (_direction == "DOWN") {
        nextPos = _nibblerBody.front() + 30;
    }
    if (_map[nextPos] == '|' || _map[nextPos] == '-') {
        _direction = oldDirection;
        _premoveDirection = "";
        return;
    }
    if (nextPos >= 0 && nextPos < static_cast<int>(_map.size()) && std::find(_nibblerBody.begin(), _nibblerBody.end(), nextPos) == _nibblerBody.end()) {
        if (_map[nextPos] == '+') {
            _nibblerBody.insert(_nibblerBody.begin(), nextPos);
            _score += 1;
        } else {
            _map[_nibblerBody.back()] = ' ';
            _nibblerBody.pop_back();
            _nibblerBody.insert(_nibblerBody.begin(), nextPos);
        }
        if (_map[nextPos - 30] == '~' || _map[nextPos + 30] == '~' || _map[nextPos - 1] == '~' || _map[nextPos + 1] == '~') {
            std::ofstream file; file.open("new_score.txt"); file << _score; file.close();
            endGame();
        }
        for (int pos : _nibblerBody) {
            _map[pos] = pos == _nibblerBody.front() ? '$' : '~';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } else {
        std::ofstream file; file.open("new_score.txt"); file << _score; file.close();
        endGame();
    }
}

bool Nibbler::isRunning() {
    return _isRunning;
}

void Nibbler::endGame() {
    _isRunning = false;
}

std::vector<std::string> Nibbler::handleEvent(std::string event) {
    if (event == "ESC")
        endGame();
    else if (event == "R")
        init();
    else
        moveNibbler(event);
    return {};
}

std::vector<std::string> Nibbler::getMap() {
    std::vector<std::string> mapVector;
    std::istringstream iss(_map);
    std::string line;
    while (std::getline(iss, line, '\n')) {
        mapVector.push_back(line);
    }
    return mapVector;
}

extern "C" IGame *createGame() {
    return new Nibbler();
}

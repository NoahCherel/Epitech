/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../include/snake.hpp"

Snake::Snake() {
    //init();
}

Snake::~Snake() {
    stop();
}

std::string Snake::getName() {
    return "snake";
}

void Snake::init() {
    _direction = "LEFT";
    _map = "";
    _snakeBody.clear();
    _wall = "-----------------------------\n";
    for (int i = 0; i < 16; i++) {
        _wall += "|                           |\n";
    }
    _wall += "-----------------------------\n";
    _isRunning = true;
    srand(time(NULL));
    int snakePos = 210 % (_wall.size() - 32) + 16;
    _map = _wall.substr(0, snakePos) + "~~~~" + _wall.substr(snakePos + 4);
    for (int i = 0; i < 4; i++) {
        _snakeBody.push_back(snakePos + i);
    }
    int fruitPos = rand() % (_wall.size() - 32) + 16;
    while (_map[fruitPos] != ' ') {
        fruitPos = rand() % (_wall.size() - 32) + 16;
    }
    _map[fruitPos] = '+';
    _isRunning = true;
}

int Snake::stop() {
    _isRunning = false;
    return _score;
}

bool Snake::isRunning() {
    return _isRunning;
}

void Snake::endGame() {
    _isRunning = false;
}

void Snake::moveSnake(std::string event) {
    std::this_thread::sleep_for(std::chrono::milliseconds(125));
    int nextPos = -1;
    switch(event[0]) {
        case 'L': _direction = _direction == "RIGHT" ? "RIGHT" : "LEFT"; break;
        case 'R': _direction = _direction == "LEFT" ? "LEFT" : "RIGHT"; break;
        case 'U': _direction = _direction == "DOWN" ? "DOWN" : "UP"; break;
        case 'D': _direction = _direction == "UP" ? "UP" : "DOWN"; break;
        default: break;
    }
    if (_direction == "LEFT") {
        nextPos = _snakeBody.front() - 1;
    } else if (_direction == "RIGHT") {
        nextPos = _snakeBody.front() + 1;
    } else if (_direction == "UP") {
        nextPos = _snakeBody.front() - 30;
    } else if (_direction == "DOWN") {
        nextPos = _snakeBody.front() + 30;
    }
    if (nextPos >= 0 && nextPos < static_cast<int>(_map.size()) && _map[nextPos] != '|' && _map[nextPos] != '-' && std::find(_snakeBody.begin(), _snakeBody.end(), nextPos) == _snakeBody.end()) {
        if (_map[nextPos] == '+') {
            _snakeBody.insert(_snakeBody.begin(), nextPos);
            _score++;
            int newFruitPos = rand() % (_map.size() - 2) + 1;
            while (_map[newFruitPos] != ' ') {
                newFruitPos = rand() % (_map.size() - 2) + 1;
            }
            _map[newFruitPos] = '+';
        } else {
            _map[_snakeBody.back()] = ' ';
            _snakeBody.pop_back();
            _snakeBody.insert(_snakeBody.begin(), nextPos);
        }
        for (int pos : _snakeBody) {
            _map[pos] = pos == _snakeBody.front() ? '$' : '~';
        }
    } else {
        std::ofstream file; file.open("new_score.txt"); file << _score; file.close();
        endGame();
    }
}

std::vector<std::string> Snake::handleEvent(std::string event) {
    if (event == "ESC")
        endGame();
    else if (event == "R")
        init();
    else
        moveSnake(event);
    return {};
}

std::vector<std::string> Snake::getMap() {
    std::vector<std::string> mapVector;
    std::istringstream iss(_map);
    std::string line;
    while (std::getline(iss, line, '\n')) {
        mapVector.push_back(line);
    }
    return mapVector;
}

extern "C" IGame *createGame() {
    return new Snake();
}

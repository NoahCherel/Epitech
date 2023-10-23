/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_

    #include "../../../interfaces/IGame.hpp"
    #include <iostream>
    #include <string>
    #include <vector>
    #include <time.h>
    #include <thread>
    #include <ctime>
    #include <thread>
    #include <chrono>
    #include <algorithm>
    #include <cstdlib>
    #include <fstream>

    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler();
            std::string getName();
            void init();
            int stop();
            bool isRunning();
            void endGame();
            void moveNibbler(std::string event);
            std::vector<std::string> handleEvent(std::string event);
            std::vector<std::string> getMap();

        protected:
        private:
            std::string _map;
            std::vector<int> _nibblerBody;
            std::string _direction;
            std::string _premoveDirection = "";
            bool _isRunning;
            int _score;
            int test;
    };

#endif /* !NIBBLER_HPP_ */

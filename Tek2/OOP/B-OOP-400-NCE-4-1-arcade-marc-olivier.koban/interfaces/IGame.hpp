/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

    #include <iostream>
    #include <string>
    #include <vector>
    #include <time.h>
    #include <thread>
    #include <ctime>
    #include <chrono>
    #include <algorithm>
    #include <cstdlib>
    #include <fstream>
    #include <sstream>

    class IGame {
        public:
            IGame() = default;
            virtual ~IGame() = default;
            virtual std::string getName() = 0;
            virtual void init() = 0;
            virtual int stop() = 0;
            virtual bool isRunning() = 0;
            virtual void endGame() = 0;
            virtual std::vector<std::string> handleEvent(std::string event) = 0;
            virtual std::vector<std::string> getMap() = 0;

        protected:
        private:
    };

#endif /* !IGAME_HPP_ */

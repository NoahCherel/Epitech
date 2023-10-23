/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "../../../interfaces/IGame.hpp"

    class Snake : public IGame {
        public:
            Snake();
            ~Snake();
            std::string getName();
            void init();
            int stop();
            bool isRunning();
            void endGame();
            void moveSnake(std::string event);
            std::vector<std::string> handleEvent(std::string event);
            std::vector<std::string> getMap();

        private:
            std::string _wall;
            std::string _map;
            std::string _direction = "LEFT";
            bool _isRunning;
            std::vector<int> _snakeBody;
            int _score = 0;
    };

#endif /* !SNAKE_HPP_ */

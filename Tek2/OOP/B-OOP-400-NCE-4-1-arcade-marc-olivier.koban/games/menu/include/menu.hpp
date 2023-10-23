/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "../../../interfaces/IGame.hpp"
    #include "../../../core/include/lib.hpp"

    class Menu : public IGame {
        public:
            Menu();
            ~Menu();
            std::string getName();
            void init();
            int stop();
            bool isRunning();
            void endGame();
            std::vector<std::string> handleEvent(std::string event);
            std::vector<std::string> getMap();
            std::vector<std::vector<int>> getSymbol(char c);

        protected:
            std::string _map;
            bool _isRunning;
            std::string _wall;
        private:
            Lib _lib;
            Lib _gamelib;
            std::vector<std::string> _files;
            std::vector<std::string> find_library(std::vector<std::string> fichiers2);
            std::vector<std::string> find_game(std::vector<std::string> fichiers2);
            std::vector<std::string> libFile();
            int countVector(std::vector<std::string> vec);
            bool _isName = false;
            int countSpaceName = 0;
            int _bestScore = 0;
            std::string _name = "";
            void getScore();
    };

#endif /* !MENU_HPP_ */

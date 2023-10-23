/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include "../../../interfaces/ILibrary.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class SFML : public ILibrary {
    public:
        SFML();
        ~SFML();
        std::string getName();
        void init();
        void stop();
        void display(std::vector<std::string> map);
        void clear();
        std::string getEvent();

    protected:
    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::string event;
        std::string text;
        void loopSymbol(char symbol, size_t pos, sf::RectangleShape rectangle, std::string text, sf::RenderWindow *window);
};

#endif /* !SFML_HPP_ */

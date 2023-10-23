/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../../../interfaces/ILibrary.hpp"
#include "../include/sfml.hpp"


SFML::SFML() : window(new sf::RenderWindow(sf::VideoMode(900, 700), "ARCADE - SFML"))
{
    window->setFramerateLimit(60);
    sf::Vector2i position = sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 450,
                            sf::VideoMode::getDesktopMode().height / 2 - 350);
    window->setPosition(position);
}

SFML::~SFML()
{
    stop();
}

void SFML::init()
{
    // do nothing, window is already created in constructor
}

void SFML::clear()
{
    window->clear();
}

void SFML::display(std::vector<std::string> map)
{
    std::string text;
    for (auto &i : map) {
        text += i + '\n';
    }
    sf::Font font;
    if (!font.loadFromFile("assets/verdana.ttf")) {
        // handle error
    }
    sf::Text sfText(text, font, 30);
    sfText.setFont(font);
    sfText.setCharacterSize(30);
    int count = 0;
    int x = 0;
    while (x < (int)text.size()) {
        sfText.setString(text[count]);
        sfText.setPosition((count % 30) * 30, (count / 30) * 30);
        window->draw(sfText);
        count += 1;
        x += 1;
    }
    window->draw(sfText);

    size_t xPos = text.find('+'); size_t oPos = text.find('~');
    size_t headPos = text.find('$'); size_t spacePos = text.find(' ');
    size_t wall1Pos = text.find('|'); size_t wall2Pos = text.find('-');
    sf::RectangleShape rectangle(sf::Vector2f(30, 30));
    rectangle.setFillColor(sf::Color::Red);
    loopSymbol('+', xPos, rectangle, text, window.get());
    rectangle.setFillColor(sf::Color::Green);
    loopSymbol('$', headPos, rectangle, text, window.get());
    rectangle.setFillColor(sf::Color(0, 153, 0));
    loopSymbol('~', oPos, rectangle, text, window.get());
    rectangle.setFillColor(sf::Color::Black);
    loopSymbol(' ', spacePos, rectangle, text, window.get());
    rectangle.setFillColor(sf::Color::White);
    loopSymbol('|', wall1Pos, rectangle, text, window.get());
    loopSymbol('-', wall2Pos, rectangle, text, window.get());
    window->display();
}

void SFML::loopSymbol(char symbol, size_t pos, sf::RectangleShape rectangle, std::string text, sf::RenderWindow *window)
{
    while (pos != std::string::npos) {
        rectangle.setPosition((pos % 30) * 30, (pos / 30) * 30);
        window->draw(rectangle);
        pos = text.find(symbol, pos + 1);
    }
}

std::string SFML::getEvent()
{
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
            return "QUIT";
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Numpad4) {
                return "LEFT";
            } else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Numpad6) {
                return "RIGHT";
            } else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Numpad8) {
                return "UP";
            } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Numpad5) {
                return "DOWN";
            } else if (event.key.code == sf::Keyboard::Escape) {
                return "ESC";
            } else if (event.key.code == sf::Keyboard::Enter) {
                return "ENTER";
            } else if (event.key.code == sf::Keyboard::Space) {
                return "SPACE";
            } else if (event.key.code == sf::Keyboard::BackSpace) {
                return "BACKSPACE";
            } else if (event.key.code == sf::Keyboard::F4) {
                return "F4";
            } else if (event.key.code == sf::Keyboard::F1) {
                return "F1";
            } else if (event.key.code == sf::Keyboard::F2) {
                return "F2";
            } else if (event.key.code == sf::Keyboard::F3) {
                return "F3";
            } else if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
                char letter = 'A' + (event.key.code - sf::Keyboard::A);
                std::string result = std::string(1, letter);
                return result;
            }
        }
    }
    return "";
}


void SFML::stop()
{
    window->close();
}

std::string SFML::getName()
{
    return "sfml";
}

extern "C" ILibrary *createLibrary() {
    return new SFML();
}

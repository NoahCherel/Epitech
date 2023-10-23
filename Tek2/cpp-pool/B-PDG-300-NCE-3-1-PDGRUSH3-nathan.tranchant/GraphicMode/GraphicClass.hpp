/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** GraphicClass
*/

#ifndef GRAPHICCLASS_HPP_
    #define GRAPHICCLASS_HPP_

    #include "../Corefiles/Core.hpp"
    #include "../IMonitorDisplay.hpp"
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <thread>
    #include <chrono>
    #include <fstream>
    #include <sstream>
    #include <unistd.h>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>

    class GraphicClass : public IMonitorDisplay {
        enum Skin {
            DEFAULT,
            DARK,
            LIGHT
        };
        public:
        GraphicClass();
        ~GraphicClass();
        void init(Core *core);
        void setSkin(Skin skin);
        void updateSkin();
        void setupText(sf::Text &text, sf::Font &font);
        void DisplayAll(sf::Text &text, char *hostname, std::string username, struct utsname unameData, sf::RenderWindow &window);
        std::string getCpuModel();
        float getCpuFrequency();
        int getCpuCores();
        std::vector<int> getCpuUsage();
        void setBar(sf::Text &text, sf::RenderWindow &window, std::vector<int> values);
    private:
        Skin _skin;
        sf::Color _backgroundColor;
        sf::Color _textColor;
};

#endif /* !GRAPHICCLASS_HPP_ */

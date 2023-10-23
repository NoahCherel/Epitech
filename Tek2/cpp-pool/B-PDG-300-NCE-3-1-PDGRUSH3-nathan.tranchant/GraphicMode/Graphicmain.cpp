/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Graphicmain
*/

#include "GraphicClass.hpp"
#include "../Corefiles/Core.hpp"
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

double getCoreUsage()
{
    std::ifstream stat_file("/proc/stat");
    std::string line;
    std::getline(stat_file, line);
    stat_file.close();

    int user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(line.c_str(), "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    int total = user + nice + system + idle + iowait + irq + softirq + steal;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    stat_file.open("/proc/stat");
    std::getline(stat_file, line);
    stat_file.close();

    int user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2;
    sscanf(line.c_str(), "cpu %d %d %d %d %d %d %d %d", &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2);
    int total2 = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;

    int active = total2 - total - (idle2 - idle);
    return (double)active / (total2 - total) * 100;
}

std::vector<double> getCoreUsagePerCore()
{
    std::ifstream stat_file("/proc/stat");
    std::string line;
    std::vector<int> prev_values;
    std::vector<int> curr_values;
    while (std::getline(stat_file, line))
    {
        if (line.find("cpu") == 0 && line.find("cpu ") != 0)
        {
            int user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(line.c_str(), "cpu%*d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            prev_values.push_back(user + nice + system + idle + iowait + irq + softirq + steal);
            prev_values.push_back(idle);
        }
    }
    stat_file.close();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    stat_file.open("/proc/stat");
    while (std::getline(stat_file, line))
    {
        if (line.find("cpu") == 0 && line.find("cpu ") != 0)
        {
            int user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(line.c_str(), "cpu%*d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            curr_values.push_back(user + nice + system + idle + iowait + irq + softirq + steal);
            curr_values.push_back(idle);
        }
    }
    stat_file.close();

    std::vector<double> usage_percentages;
    for (int i = 0; i < curr_values.size(); i += 2)
    {
        int total_time = curr_values[i] - prev_values[i];
        int idle_time = curr_values[i + 1] - prev_values[i + 1];
        double usage_percentage = (double)(total_time - idle_time) / total_time * 100;
        usage_percentages.push_back(usage_percentage);
    }

    return usage_percentages;
}

float GraphicClass::getCpuFrequency()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string frequency;
    while (std::getline(file, line)) {
        if (line.find("cpu MHz") != std::string::npos) {
            frequency = line.substr(line.find(":") + 2);
            break;
        }
    }
    file.close();
    return std::stof(frequency);
}

int GraphicClass::getCpuCores()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    int cores = 0;
    while (std::getline(file, line)) {
        if (line.find("cpu cores") != std::string::npos) {
            cores = std::stoi(line.substr(line.find(":") + 2));
            break;
        }
    }
    file.close();
    return cores;
}

void GraphicClass::setupText(sf::Text &text, sf::Font &font)
{
    text.setFont(font);
    text.setFillColor(_textColor);
    text.setCharacterSize(12);
}

void GraphicClass::DisplayAll(sf::Text &text, char *hostname, std::string username, struct utsname unameData, sf::RenderWindow &window)
{
    time_t now = time(0);
    char *dt = ctime(&now);
    struct sysinfo info;
    sysinfo(&info);
    text.setString("Hostname: " + std::string(hostname) + "\nUsername: " + username + "\nOS: " + unameData.sysname + " " + unameData.release + " " + unameData.machine + "\nKernel: " + unameData.version + "\nTime: " + std::string(dt) + "\nCPU Frequency: " + std::to_string(getCpuFrequency()) + " MHz\nCPU Cores: " + std::to_string(getCpuCores()) + "\nCPU Usage: " + std::to_string(getCoreUsage()) + "%\nRAM: " + std::to_string(info.totalram / 1024 / 1024) + " MB\nRAM Usage: " + std::to_string((info.totalram - info.freeram) / 1024 / 1024) + " MB\nRAM Usage: " + std::to_string((info.totalram - info.freeram) * 100 / info.totalram) + "%\nSwap: " + std::to_string(info.totalswap / 1024 / 1024) + " MB\nSwap Usage: " + std::to_string((info.totalswap - info.freeswap) / 1024 / 1024) + " MB\nSwap Usage: " + std::to_string((info.totalswap - info.freeswap) * 100 / info.totalswap) + "%");
    text.setPosition(10, 10);
    window.draw(text);
}

void drawRectangle(sf::RenderWindow& window, std::vector<double> usage_percentages, sf::Font& font) {
    sf::Vector2u windowSize = window.getSize();
    int rectWidth = windowSize.x * 0.1;
    int rectHeight = windowSize.y * 0.04;
    int x = windowSize.x * 0.9;
    int y = windowSize.y * 0.05;
    for (int i = 0; i < usage_percentages.size(); i++) {
        sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Black);
        sf::Text text;
        text.setFont(font);
        text.setString("Core " + std::to_string(i + 1));
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 5, y + 5);
        sf::RectangleShape rectUsage(sf::Vector2f((rectWidth * usage_percentages[i]) / 100, rectHeight));
        rectUsage.setPosition(x, y);
        rectUsage.setFillColor(sf::Color::Red);
        window.draw(rect);
        window.draw(rectUsage);
        window.draw(text);
        y += rectHeight + 10;
    }
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(80, 550));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(700, 25);
    window.draw(rectangle);
}

void displayNetworkLoad(sf::RenderWindow& window, sf::Font& font, Core* core) {
    auto network_load = core->getNetworkLoad();
    int y_pos = 250;
    for (const auto& [interface, bytes] : network_load) {
        sf::Text interface_text(interface, font, 12);
        interface_text.setPosition(10, y_pos + 20);
        window.draw(interface_text);
        sf::RectangleShape load_bar(sf::Vector2f((float)bytes.first / 1000000, 20));
        load_bar.setSize(sf::Vector2f(std::min((float)bytes.first / 1000000, 60.0f), 20));
        load_bar.setPosition(150, y_pos + 25);
        load_bar.setFillColor(sf::Color::Red);
        window.draw(load_bar);
        sf::Text received_text("Received: " + std::to_string(bytes.first / 1000000) + "MB", font, 12);
        sf::RectangleShape received_bar(sf::Vector2f(std::min((float)bytes.first / 1000000,60.0f), 20));
        received_bar.setPosition(150, y_pos + 25);
        received_bar.setFillColor(sf::Color::Red);
        window.draw(received_bar);
        received_text.setPosition(10, y_pos + 30);
        window.draw(received_text);
        sf::RectangleShape sent_bar(sf::Vector2f((float)bytes.second / 1000000, 20));
        sent_bar.setPosition(150, y_pos + 35);
        sent_bar.setSize(sf::Vector2f(std::min((float)bytes.second / 1000000, 60.0f), 20));
        sent_bar.setFillColor(sf::Color::Red);
        window.draw(sent_bar);
        sf::Text sent_text("Sent: " + std::to_string(bytes.second / 1000000) + "MB", font, 12);
        sent_text.setPosition(10, y_pos + 40);
        window.draw(sent_text);
        y_pos += 50;
    }
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(250, 200));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(0, 250);
    window.draw(rectangle);

}

void GraphicClass::init(Core *core)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Graphic Mode");
    sf::Font font;
    sf::Text text;
    if (!font.loadFromFile("ARIAL.TTF"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    setSkin(Skin::DARK);
    setupText(text, font);
    char hostname[512];
    gethostname(hostname, 512);
    std::string username = std::getenv("USER");
    struct utsname unameData;
    uname(&unameData);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        text.setString("CPU Usage of each core:");
        text.setPosition(10, 600 - 75);
        window.draw(text);
        window.clear(_backgroundColor);
        std::vector<double> usage = getCoreUsagePerCore();
        for(int i = 0; i < usage.size(); i++) {
            drawRectangle(window, usage, font);
        }
        displayNetworkLoad(window, font, core);
        DisplayAll(text, hostname, username, unameData, window);
        window.display();
    }
}

GraphicClass::GraphicClass()
{
    core = new Core();
    init(core);
}

GraphicClass::~GraphicClass()
{
    free(this);
    delete this;
}

void GraphicClass::setSkin(Skin skin)
{
    _skin = skin;
    updateSkin();
}

void GraphicClass::updateSkin()
{
    switch (_skin)
    {
        case Skin::DEFAULT:
            _backgroundColor = sf::Color::White;
            _textColor = sf::Color::Black;
            break;
        case Skin::DARK:
            _backgroundColor = sf::Color::Black;
            _textColor = sf::Color::White;
            break;
        case Skin::LIGHT:
            _backgroundColor = sf::Color::Yellow;
            _textColor = sf::Color::Blue;
            break;
    }
}

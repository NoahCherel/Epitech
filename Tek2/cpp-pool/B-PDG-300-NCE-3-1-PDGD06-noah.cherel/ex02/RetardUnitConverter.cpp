/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RetardUnitConverter
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

void RetardUnitConverter()
{
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        double temp;
        std::string scale;
        iss >> temp >> scale;
        if (scale == "Celsius") {
            std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << (9.0 / 5.0 * temp + 32) << "";
            std::cout << std::right << std::setw(16) << std::setprecision(5) << "Fahrenheit" << std::endl;
        } else if (scale == "Fahrenheit") {
            std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << (5.0 / 9.0 * (temp - 32)) << "";
            std::cout << std::right << std::setw(16) << std::setprecision(5) << "Celsius" << std::endl;
        }
    }
}

int main()
{
    RetardUnitConverter();
    return 0;
}

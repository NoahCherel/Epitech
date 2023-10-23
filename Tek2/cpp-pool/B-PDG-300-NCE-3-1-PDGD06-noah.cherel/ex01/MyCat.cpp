/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Mycat
*/

#include <iostream>
#include <fstream>

int MyCat(int argc, char *argv[])
{
    if (argc == 1) {
        std::string line;
        while (std::getline(std::cin, line)) std::cout << line << std::endl;
    }
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) std::cout << line << std::endl;
            file.close();
        } else {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" 
            << std::endl;
            return 84;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (MyCat(argc, argv) == 84) return 84;
    return 0;
}
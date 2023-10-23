/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** core
*/

#include "../include/core.hpp"

int help(char **av) {
    // Displays the help message
    std::cout << "USAGE: " << av[0] << " <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
    return 0;
}

int exec(char *file) {
    // Opens the scene file
    Config cfg;
    cfg.readFile(file);
    // Executes the raytracer
    std::vector<std::vector<sf::Color>> framebuffer =
        generate_buffer(cfg.lookup("camera.resolution.width"),
        cfg.lookup("camera.resolution.height"));
    framebuffer = raytrace(framebuffer, &cfg);
    // display_ppm(framebuffer);
    // Saves the image as a ppm file
    char *filename = file;
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '.') {
            filename[i] = '\0'; break;
        }
    }
    std::string str = filename; str += ".ppm"; filename = (char *)str.c_str();
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '/') {
            filename = &filename[i + 1]; break;
        }
    }
    output_ppm(framebuffer, filename);
    display_window(framebuffer);
    return 0;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        return 84;
    }
    if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) return help(av);
    Config cfg;
    try {
        cfg.readFile(av[1]);
    } catch (const FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl; return 84;
    } catch (const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                << " - " << pex.getError() << std::endl; return 84;
    }
    return exec(av[1]);
}

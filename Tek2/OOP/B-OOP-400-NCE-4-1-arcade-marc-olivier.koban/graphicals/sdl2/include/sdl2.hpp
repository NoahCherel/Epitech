/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
    #define SDL2_HPP_

#include "../../../interfaces/ILibrary.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SDL2 : public ILibrary {
    public:
        SDL2();
        ~SDL2();
        std::string getName();
        void init();
        void stop();
        void display(std::vector<std::string> map);
        void clear();
        std::string getEvent();

    protected:
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
        void textMenu(std::string text, int pos);
        void loopSymbol(std::string text, size_t pos, char symbol, SDL_Rect rectangle, SDL_Renderer* renderer);
};

#endif /* !SDL2_HPP_ */

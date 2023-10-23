/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../../../interfaces/ILibrary.hpp"
#include "../include/sdl2.hpp"

SDL2::SDL2() : window(nullptr), renderer(nullptr), font(nullptr) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("ARCADE - SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 950, 700, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("assets/verdana.ttf", 30);
    if (!font) { /* handle error */ }
}

SDL2::~SDL2() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void SDL2::init() {
    /* do nothing, window is already created in constructor */
}

void SDL2::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SDL2::display(std::vector<std::string> map)
{
    std::string text;
    for (auto &line : map) {
        text += line + '\n';
    }
    SDL_Rect rectangle; rectangle.w = 30; rectangle.h = 30;
    const size_t xPos = text.find('+');
    const size_t oPos = text.find('~');
    const size_t headPos = text.find('$');
    const size_t spacePos = text.find(' ');
    const size_t wall1Pos = text.find('|');
    const size_t wall2Pos = text.find('-');
    if (text.find('>') != std::string::npos) {
        for (size_t y = 0; y < text.size(); ++y) {
            if (text[y] != '\n') {
                std::string c(1, text[y]);
                textMenu(c, y);
            }
        }
    }
    rectangle.x = 0; rectangle.y = 0;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    loopSymbol(text, xPos, '+', rectangle, renderer);
    rectangle.x = 0; rectangle.y = 0;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    loopSymbol(text, headPos, '$', rectangle, renderer);
    rectangle.x = 0; rectangle.y = 0;
    SDL_SetRenderDrawColor(renderer, 0, 153, 0, 255);
    loopSymbol(text, oPos, '~', rectangle, renderer);
    rectangle.x = 0; rectangle.y = 0;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    loopSymbol(text, spacePos, ' ', rectangle, renderer);
    rectangle.x = 0; rectangle.y = 0;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    loopSymbol(text, wall1Pos, '|', rectangle, renderer);
    loopSymbol(text, wall2Pos, '-', rectangle, renderer);
    SDL_RenderPresent(renderer);
}

void SDL2::textMenu(std::string text, int pos) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {255, 255, 255, 255});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {(pos % 30) * 30, (pos / 30) * 30, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    //SDL_FreeSurface(surface);
}

void SDL2::loopSymbol(std::string text, size_t pos, char symbol, SDL_Rect rectangle, SDL_Renderer* renderer)
{
    while (pos != std::string::npos) {
        rectangle.x = (pos % 30) * 30;
        rectangle.y = (pos / 30) * 30;
        SDL_RenderFillRect(renderer, &rectangle);
        pos = text.find(symbol, pos + 1);
    }
}

std::string SDL2::getEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return "QUIT";
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_KP_4:
                    return "LEFT";
                case SDLK_RIGHT:
                case SDLK_KP_6:
                    return "RIGHT";
                case SDLK_UP:
                case SDLK_KP_8:
                    return "UP";
                case SDLK_DOWN:
                case SDLK_KP_5:
                    return "DOWN";
                case SDLK_BACKSPACE:
                    return "BACKSPACE";
                case SDLK_SPACE:
                    return "SPACE";
                case SDLK_ESCAPE:
                    return "ESC";
                case SDLK_RETURN:
                    return "ENTER";
                case SDLK_r:
                    return "R";
                case SDLK_F1:
                    return "F1";
                case SDLK_F2:
                    return "F2";
                case SDLK_F3:
                    return "F3";
                case SDLK_F4:
                    return "F4";
                default:
                    if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) {
                        char letter = 'A' + (event.key.keysym.sym - SDLK_a);
                        std::string result = std::string(1, letter);
                        return result;
                    }
            }
        }
    }
    return "";
}

void SDL2::stop() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

std::string SDL2::getName()
{
    return "sdl2";
}

extern "C" ILibrary *createLibrary()
{
    return new SDL2();
}

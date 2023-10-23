/*
** EPITECH PROJECT, 2022
** MY RPG : GAME.C
** File description:
** RPG cool game
*/

#include "rpg.h"

int moove_player(int dir, scene_t *scene, global_t *g)
{
    switch (dir) {
        case 0: g->pos_player.y += SPEED, g->head = 0;
            if (condition_getpixel(g, scene->map)) {
                g->pos_player.y -= SPEED; return 1;
            } break;
        case 1: g->pos_player.y -= SPEED, g->head = 1;
            if (condition_getpixel(g, scene->map)) {
                g->pos_player.y += SPEED; return 1;
            } break;
        case 2: g->pos_player.x += SPEED, g->head = 2;
            if (condition_getpixel(g, scene->map)) {
                g->pos_player.x -= SPEED; return 1;
            } break;
        case 3: g->pos_player.x -= SPEED, g->head = 3;
            if (condition_getpixel(g, scene->map)) {
                g->pos_player.x += SPEED; return 1;
            } break;
        default: return (0);
    }
    int c = condition_pixel(g, scene); if (c != 0) return c;
}

int condition_pixel(global_t *g, scene_t *scene)
{
    if (condition_pixel_red(g, scene->map) == 1 && scene->name == GAME)
    return (5);
    if (X_BTW(832, 840) && g->pos_player.y == 768 && scene->name == ZONE_1)
    return (6);
    if (condition_pixel_blue(g, scene->map) == 1 && scene->name == ZONE_1)
    return (7);
    if (g->pos_player.x >= 896 && g->pos_player.y == 476 && g->head == 1 &&
    scene->name == ZONE_1 && g->pos_player.x <= 904) return (8);
    if (condition_pixel_red(g, scene->map) == 1 && scene->name == SHOP)
    return (9);
}

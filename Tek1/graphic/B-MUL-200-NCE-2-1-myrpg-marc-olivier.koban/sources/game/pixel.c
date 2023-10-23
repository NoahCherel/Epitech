/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** pixel.c
*/

#include "rpg.h"

int condition_getpixel(global_t *g, map_t *map)
{
    if (sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).a == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).b == 0
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).r == 0
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).g == 0) {
        return (1);
    } else {
        return (0);
    }
}

int condition_pixel_red(global_t *g, map_t *map)
{
    if (sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).a == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).b == 0
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).r == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).g == 0) {
        return (1);
    } else {
        return (0);
    }
}

int condition_pixel_blue(global_t *g, map_t *map)
{
    if (sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).a == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).b == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).r == 0
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).g == 0) {
        return (1);
    } else {
        return (0);
    }
}

int condition_pixel_green(global_t *g, map_t *map)
{
    if (sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).a == 255
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).b == 0
    && sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).r == 0 &&
    sfImage_getPixel(map->image, g->pos_player.x, g->pos_player.y).g == 255) {
        return (1);
    } else {
        return (0);
    }
}

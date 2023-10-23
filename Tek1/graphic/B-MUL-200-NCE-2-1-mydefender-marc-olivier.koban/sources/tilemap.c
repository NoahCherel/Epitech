/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** tilemap
*/

#include "../include/my.h"

map_t *set_tile(map_t *map, int i, int j, int k)
{
    map->tile_1[i].left = j;
    map->tile_1[i].top = k;
    map->tile_1[i].width = map->width;
    map->tile_1[i].height = map->height;
    return (map);
}

map_t *map(map_t *map)
{
    map = malloc(sizeof(map_t));
    map->tile = sfSprite_create();
    map->tiletext = sfTexture_createFromFile("img/a1.png", NULL);
    sfSprite_setTexture(map->tile, map->tiletext, sfFalse);
    map->width = 100; map->height = 100;
    set_tile(map, 0, 1300, 300);
    set_tile(map, 1, 1000, 400);
    set_tile(map, 2, 500, 400);
    set_tile(map, 3, 100, 550);
    set_tile(map, 4, 900, 100);
    set_tile(map, 5, 1200, 400);
    set_tile(map, 6, 1300, 400);
    set_tile(map, 7, 1100, 400);
    set_tile(map, 8, 900, 400);
    set_tile(map, 9, 0, 300);
    return (map);
}

void draw_tile(global_t *win, sfIntRect placeHolder, int row, int column)
{
    sfSprite_setTextureRect(win->map->tile, placeHolder);
    sfSprite_setPosition(win->map->tile, (sfVector2f) {(row * win->map->width)
    , (column * win->map->height + 320)});
    sfRenderWindow_drawSprite(win->window->window, win->map->tile, NULL);
}

void draw(global_t *win, map_t *mape)
{
    sfIntRect placeHolder; for (int row = 0; row < 13; row++) {
        for (int column = 0; column < 7; column++) {
            switch (win->map->list[row][column]) {
            case 1: placeHolder = mape->tile_1[0]; break;
            case 2: placeHolder = mape->tile_1[1]; break;
            case 3: placeHolder = mape->tile_1[2]; break;
            case 4: placeHolder = mape->tile_1[3]; break;
            case 5: placeHolder = mape->tile_1[4]; break;
            case 6: placeHolder = mape->tile_1[5]; break;
            case 7: placeHolder = mape->tile_1[6]; break;
            case 8: placeHolder = mape->tile_1[7]; break;
            case 9: placeHolder = mape->tile_1[8]; break;
            case 0: placeHolder = mape->tile_1[4]; break;
            default:
                switch (win->map->map_2d[row][column])
                    case 'a': placeHolder = mape->tile_1[9]; break;
            }
            draw_tile(win, placeHolder, row, column);
        }
    }
}

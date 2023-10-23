/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** map
*/

#include "rpg.h"

map_t *init_map(map_t *map, char *the_map, sfIntRect rect)
{
    map->pos = (sfVector2f){0, 0};
    map->rect = rect;
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile(the_map, NULL);
    map->go_up = sfFalse;
    map->go_down = sfFalse;
    map->go_left = sfFalse;
    map->go_right = sfFalse;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setTextureRect(map->sprite, map->rect);
    sfSprite_setPosition(map->sprite, map->pos);
    sfSprite_setScale(map->sprite, (sfVector2f){5, 5});
    return (map);
}

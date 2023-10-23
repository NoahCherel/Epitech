/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** mouse
*/

#include "../include/my.h"

mouse_t *set_cursor(mouse_t *cursor)
{
    cursor = malloc(sizeof(mouse_t));
    cursor->cursor = sfSprite_create();
    cursor->text = sfTexture_createFromFile("img/cursor.png",NULL);
    sfSprite_setTexture(cursor->cursor, cursor->text, sfTrue);
    return (cursor);
}

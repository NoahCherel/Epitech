/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** utils3
*/

#include "../include/my.h"

void move(global_t *a)
{
    if (a->event.key.code == sfKeyUp && a->c->saut != sfTrue)
        a->j->velocityX -= 30;
    if (a->event.key.code == sfKeyRight) {
        a->j->velocityY = 0; a->j->velocityY += 1;
        }
    if (a->event.key.code == sfKeyLeft) {
        a->j->velocityY = 0; a->j->velocityY -= 1;
        }
    if (a->event.key.code == sfKeyDown) a->j->velocityY = 0;
}

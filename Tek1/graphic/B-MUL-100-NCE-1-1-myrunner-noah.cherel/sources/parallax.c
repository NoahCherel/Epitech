/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Load_struct
*/

#include "../include/my.h"

parallax_t *parallax(parallax_t* p)
{
    p = malloc(sizeof(parallax_t));
    p->back = sfSprite_create(); p->far = sfSprite_create();
    p->Forefront = sfSprite_create();
    sfTexture *a = sfTexture_createFromFile("Images/back.png", NULL);
    sfTexture *b = sfTexture_createFromFile("Images/far.png", NULL);
    sfTexture *c = sfTexture_createFromFile("Images/foreground.png", NULL);
    sfSprite_setTexture(p->back, a, sfTrue);
    sfSprite_setTexture(p->far, b, sfTrue);
    sfSprite_setTexture(p->Forefront, c, sfTrue);
    sfSprite_setPosition(p->back, (sfVector2f){0, 250});
    sfSprite_setPosition(p->far, (sfVector2f){0, 0});
    sfSprite_setPosition(p->Forefront, (sfVector2f){0, 500});
    return (p);
}

void move_parralax(parallax_t *p)
{
    p->pos1 = sfSprite_getPosition(p->back);
    p->pos2 = sfSprite_getPosition(p->far);
    p->pos3 = sfSprite_getPosition(p->Forefront);
    if (p->pos1.x <= -1600)
        sfSprite_setPosition(p->back, (sfVector2f){0, 250});
    if (p->pos2.x <= -1550)
        sfSprite_setPosition(p->far, (sfVector2f){0, 0});
    if (p->pos3.x <= -1600)
        sfSprite_setPosition(p->Forefront, (sfVector2f){0, 500});
    sfSprite_move(p->back, (sfVector2f){-2, 0});
    sfSprite_move(p->far, (sfVector2f) {-1, 0});
    sfSprite_move(p->Forefront, (sfVector2f){-3, 0});
}

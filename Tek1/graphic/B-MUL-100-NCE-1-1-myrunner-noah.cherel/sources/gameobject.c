/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** gameobject
*/

#include "../include/my.h"

coin_t *coin(coin_t *g)
{
    g = malloc(sizeof(coin_t));
    g->s = sfSprite_create();
    sfTexture *a = sfTexture_createFromFile("Images/coin.png", NULL);
    sfSprite_setTexture(g->s, a, sfTrue);
    sfSprite_setPosition(g->s, (sfVector2f){1100, 750});
    g->rect.top = 0; g->rect.left = 0;
    g->rect.width = 125; g->rect.height = 150;
    sfSprite_setTextureRect(g->s, g->rect);
    return (g);
}

monster_t *monster(monster_t *g)
{
    g = malloc(sizeof(monster_t));
    g->m = sfSprite_create();
    sfTexture *a = sfTexture_createFromFile("Images/wolf1.png", NULL);
    sfSprite_setTexture(g->m, a, sfTrue);
    sfSprite_setPosition(g->m, (sfVector2f){1300, 790});
    g->rect.top = 0; g->rect.left = 0;
    g->rect.width = 185; g->rect.height = 150;
    sfSprite_setTextureRect(g->m, g->rect);
    return (g);
}

gameobject_t *objet(gameobject_t *e)
{
    e = malloc(sizeof(gameobject_t));
    e->monster = monster(e->monster);
    e->c = coin(e->c);
    return (e);
}

void move_object(gameobject_t *c)
{
    c->c->pos = sfSprite_getPosition(c->c->s);
    c->monster->pos = sfSprite_getPosition(c->monster->m);
    if (c->c->pos.x <= 0)
        sfSprite_setPosition(c->c->s, (sfVector2f) {1700, rand()% 500});
    if (c->monster->pos.x <= 0)
        sfSprite_setPosition(c->monster->m, (sfVector2f){1700, 790});
    sfSprite_move(c->c->s, (sfVector2f){-8, 0});
    sfSprite_move(c->monster->m, (sfVector2f){-8, 0});
}

void rect_object(gameobject_t *c)
{
    sfSprite_setTextureRect(c->c->s, c->c->rect);
    c->c->rect.left += 140;
    if (c->c->rect.left > 800) c->c->rect.left = 0;
    sfSprite_setTextureRect(c->c->s, c->c->rect);
    sfSprite_setTextureRect(c->monster->m, c->monster->rect);
    c->monster->rect.left += 205;
    if (c->monster->rect.left > 1200) c->monster->rect.left = 0;
    sfSprite_setTextureRect(c->monster->m, c->monster->rect);
}

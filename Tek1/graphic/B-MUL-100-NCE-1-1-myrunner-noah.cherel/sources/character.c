/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** character
*/

#include "../include/my.h"

character_t *character_init(character_t *perso)
{
    perso = malloc(sizeof(character_t));
    perso->d = sfFalse;
    perso->saut = sfFalse;
    perso->texture = sfTexture_createFromFile("Images/walking.png", NULL);
    perso->health_text = sfTexture_createFromFile("Images/health.png", NULL);
    perso->sprite = sfSprite_create(); perso->health = sfSprite_create();
    sfSprite_setPosition(perso->sprite, (sfVector2f){10, 700});
    sfSprite_setPosition(perso->health, (sfVector2f){1300, 0});
    perso->pos.y = 10; perso->pos.x = 700;
    sfSprite_setTexture(perso->sprite, perso->texture, sfTrue);
    sfSprite_setTexture(perso->health, perso->health_text, sfTrue);
    perso->rect.top = 0; perso->rect.left = 0;
    perso->rect.width = 120; perso->rect.height = 200;
    perso->health_rect.top = 0; perso->health_rect.left = 0;
    perso->health_rect.width = 100; perso->health_rect.height = 100;
    sfSprite_setTextureRect(perso->sprite, perso->rect);
    sfSprite_setTextureRect(perso->health, perso->health_rect);
    return (perso);
}

void player_life(global_t *a)
{
    int vie = 3;
    sfVector2f ps = {1125, 30};
    sfText *score = sfText_create();
    sfText_setString(score, my_inttostr(vie));
    sfFont *Font = sfFont_createFromFile("font1.ttf");
    sfText_setString(score ,"lives:"); sfText_setPosition(score, ps);
    sfText_setFont(score, Font);
    sfRenderWindow_drawText(a->window, score, NULL);
}

void move_rect(character_t *perso)
{
    sfSprite_setTextureRect(perso->sprite, perso->rect);
    perso->rect.left += 120;
    if (perso->rect.left > 1917) perso->rect.left = 0;
    sfSprite_setTextureRect(perso->sprite, perso->rect);
}

void collisions(global_t *g)
{
    int cd;
    sfVector2f player_p = sfSprite_getPosition(g->c->sprite);
    sfVector2f coin_p = sfSprite_getPosition(g->g->c->s);
    sfVector2f monster_p = sfSprite_getPosition(g->g->monster->m);
    if (player_p.x + 25 <= coin_p.x - 5 && player_p.x + 25 >= coin_p.x - 100 &&
    player_p.y <= coin_p.y + 50 && player_p.y >= coin_p.y - 190)
        g->score1->sco += 1;
    if (player_p.x + 25 <= monster_p.x - 5 && player_p.x + 25 >= monster_p.x -
    100 && player_p.y <= monster_p.y + 50 && player_p.y >= monster_p.y - 190) {
        sfSprite_setTextureRect(g->c->health, g->c->health_rect);
        g->c->health_rect.left += 100;
        if (g->c->health_rect.left >= 200) g->c->health_rect.left = 200;
        if (g->c->health_rect.left = 200) g->c->d = sfTrue;
        sfSprite_setTextureRect(g->c->health, g->c->health_rect);
    }
}

void physics(character_t *p, gravity_t *a)
{
    if (p->pos.x < 700 && sfEvtKeyPressed) {
        a->velocityX += a->gravity;
        p->saut = sfTrue;
    }
    p->pos.x += a->velocityX;
    p->pos.y += a->velocityY;
    if (p->pos.x > 700) {
        p->pos.x = 700; a->velocityX = 0;
        p->saut = sfFalse;
    }
}

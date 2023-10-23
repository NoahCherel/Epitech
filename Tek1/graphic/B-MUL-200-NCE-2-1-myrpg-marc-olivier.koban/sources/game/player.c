/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_character
*/

#include "rpg.h"

player_t *init_player(player_t *player, global_t *g, int facing)
{
    player->pos = (sfVector2f){1920 / 2 - 120 / 2, 1080 / 2 - 120 / 2};
    g->pos_player = player->pos;
    if (facing == 0) player->rect = (sfIntRect){0, 285, 120, 120};
    if (facing == 1) player->rect = (sfIntRect){0, 15, 120, 120};
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile("img/character.png", NULL);
    player->clock = sfClock_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    return (player);
}

void change_sprt(player_t *p, int sx, int sy)
{
    if (sx == 0 && sy == 0) {
        p->rect.height = 120;
        if (p->rect.top == 530) p->rect.left = 0, p->rect.top = 15;
        if (p->rect.top == 665) p->rect.left = 600;
        if (p->rect.top == 780) p->rect.left = 0, p->rect.top = 285;
        if (p->rect.top == 925) p->rect.left = 480;
    } else {
        p->rect.left += 120;
    }
}

void player_update(global_t *g, scene_t *s)
{
    double sx = 0; double sy = 0; int color = 0;
    if (press(DW) && g->text_choice == 0) {
        s->player->rect.top = 530, s->player->rect.height = 120;
        sy += SPEED; color = moove_player(0, s, g);
    } if (press(LT) && g->text_choice == 0 && sy == 0 && sx == 0) {
        s->player->rect.top = 665, s->player->rect.height = 115;
        sx += -SPEED; color = moove_player(3, s, g);
    } if (press(UP) && g->text_choice == 0 && sy == 0 && sx == 0) {
        s->player->rect.top = 780, s->player->rect.height = 120;
        sy += -SPEED; color = moove_player(1, s, g);
    } if (press(RT) && g->text_choice == 0 && sy == 0 && sx == 0) {
        s->player->rect.top = 925, s->player->rect.height = 120;
        sx += SPEED; color = moove_player(2, s, g);
    } change_sprt(s->player, sx, sy); if (s->player->rect.left > 1080)
    s->player->rect.left = 0; settext(s->player->sprite, s->player->rect);
    settext(s->map->sprite, s->map->rect);
    if (color != 1 && !(color >= 5 && color <= 9))
        s->map->rect.left += sx, s->map->rect.top += sy;
    color_switch(color, g);
}

void color_switch(int color, global_t *g)
{
    switch (color) {
        case 5: g->red = 1; break; case 6: g->red = 2; break;
        case 7: g->red = 3; break; case 8: g->red = 4; break;
        case 9: g->red = 5; break;
        default: break;
    }
}

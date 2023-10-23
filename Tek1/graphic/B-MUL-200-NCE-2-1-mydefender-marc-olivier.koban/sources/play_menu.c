/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** play_menu my_defender
*/

#include "../include/my.h"

void draw_sprite_play(global_t *a)
{
    sfRenderWindow_drawSprite(a->window->window, a->hud->tower, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->hud->money, NULL);
    sfRenderWindow_drawText(a->window->window, a->money->text, NULL);
    sfRenderWindow_drawText(a->window->window, a->money->score, NULL);
    sfRenderWindow_drawText(a->window->window, a->money->score1, NULL);
}

void display_play(global_t *a)
{
    paralax(0.02, a);
    sfRenderWindow_drawSprite(a->window->window,
    a->sprite->image_menu, NULL);
    draw(a, a->map); draw_sprite_play(a);
    tower_draw(a); scene1(a);
    sfRenderWindow_drawSprite(a->window->window, a->sprite->pause, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->sprite->life, NULL);
    sfRenderWindow_drawText(a->window->window, a->text->score, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->money->money_s, NULL);
    sfSprite_setPosition(a->mouse->cursor, a->mouse->pos);
    if (a->var->lose == sfTrue)
        lose(a);
    if (a->nb_wave >= 5 && a->var->lose == sfFalse)
        win_disp(a);
    update_tower1(a);
    sfRenderWindow_drawSprite(a->window->window, a->mouse->cursor, NULL);
}

void while_open_play(float max, global_t *a)
{
    preparation_play(a);
    int c = 0;
    while (sfRenderWindow_isOpen(a->window->window)) {
        sfRenderWindow_display(a->window->window);
        a->mouse->pos.x = sfMouse_getPositionRenderWindow(a->window->window).x
        - 45;
        a->mouse->pos.y = sfMouse_getPositionRenderWindow(a->window->window).y;
        pathfinding(a);
        display_play(a);
        c = analyse_events_play(a);
        if (c != 0) {
            while_open_pause(a);
        }
    }
}

void preparation_play(global_t *a)
{
    sfMusic_stop(a->music->music_menu);
    sfMusic_play(a->music->music_game);
    sfSprite_setPosition(a->sprite->life, (sfVector2f) {200, 0});
    sfText_setPosition(a->text->score, (sfVector2f){225, 100});
    sfText_setString(a->text->score, my_inttostr(a->var->heart));
    sfText_setString(a->money->text, my_inttostr(a->money->money));
    sfText_setCharacterSize(a->text->score, 30);
    sfText_setFont(a->text->score, a->text->font);
}

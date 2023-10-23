/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** menu_pause my_defender
*/

#include "../include/my.h"

void display_pause(global_t *a)
{
    sfRenderWindow_drawSprite(a->window->window,
    a->sprite->image_menu, NULL);
    sfSprite_setPosition(a->mouse->cursor, a->mouse->pos);
    paralax(0.05, a);
    if (a->pos->bool_sound == sfFalse) {
        sfRenderWindow_drawSprite(a->window->window,a->sprite->sound_on, NULL);
    } else {
        sfRenderWindow_drawSprite(a->window->window,a->sprite->sound_off,
        NULL);
    }
    sfRenderWindow_drawSprite(a->window->window, a->sprite->play, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->sprite->quit, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->mouse->cursor, NULL);
}

void while_open_pause(global_t *a)
{
    int c = 0;
    sfSprite_setPosition(a->sprite->sound_on, (sfVector2f){20, 820});
    sfSprite_setPosition(a->sprite->sound_off, (sfVector2f){20, 820});
    sfSprite_setPosition(a->sprite->play, (sfVector2f){700, 200});
    sfSprite_setPosition(a->sprite->quit, (sfVector2f){700, 600});
    while (sfRenderWindow_isOpen(a->window->window)) {
        sfRenderWindow_display(a->window->window);
        a->mouse->pos.x = sfMouse_getPositionRenderWindow(a->window->window).x
        - 45;
        a->mouse->pos.y = sfMouse_getPositionRenderWindow(a->window->window).y;
        display_pause(a);
        analyse_events_menu(a);
    }
}

int analyse_events_menu1(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 703 &&
        a->event->event.mouseButton.x <= 1159 &&
        a->event->event.mouseButton.y >= 200 &&
        a->event->event.mouseButton.y <= 400) {
            sfSound_play(a->music->selection);
            while_open_play(0.05, a);
        }
        if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 703 &&
        a->event->event.mouseButton.x <= 1170 &&
        a->event->event.mouseButton.y >= 600 &&
        a->event->event.mouseButton.y <= 800) {
            sfSound_play(a->music->selection);
            reset_mob_pause(a); a->money->money = 100; while_open(a);
        }
    return 0;
}

int analyse_events_menu(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window->window, &a->event->event)) {
        if (a->event->event.type == sfEvtClosed)
            sfRenderWindow_close(a->window->window);
        if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
            a->event->event.mouseButton.x >= 21 &&
            a->event->event.mouseButton.x <= 214 &&
            a->event->event.mouseButton.y >= 837 &&
            a->event->event.mouseButton.y <= 1010) {
            song_gestion(a);
        }
        analyse_events_menu1(a);
        if (a->event->event.type == sfEvtKeyPressed &&
        a->event->event.key.code == sfKeyEscape)
            while_open_play(0.05, a);
    }
    return 0;
}

void song_gestion(global_t *a)
{
    if (a->pos->music_menu == sfTrue) {
        if (a->pos->bool_sound == sfFalse) {
            a->pos->bool_sound = sfTrue;
            sfMusic_setVolume(a->music->music_menu, 0);
            sfMusic_setVolume(a->music->music_game, 0);
        } else {
            a->pos->bool_sound = sfFalse;
            sfMusic_setVolume(a->music->music_menu, 50);
            sfMusic_setVolume(a->music->music_game, 50);
        }
    }
    song_gestion2(a);
}

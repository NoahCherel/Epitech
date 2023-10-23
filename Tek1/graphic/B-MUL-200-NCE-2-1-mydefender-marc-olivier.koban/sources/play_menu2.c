/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** play_menu2
*/

#include "../include/my.h"

int analyse_event_play_3(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 950 &&
        a->event->event.mouseButton.x <= 1300 &&
        a->event->event.mouseButton.y >= 500 &&
        a->event->event.mouseButton.y <= 600 && a->nb_wave >= 5) {
            sfRenderWindow_close(a->window->window);
        }
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 550 &&
        a->event->event.mouseButton.x <= 900 &&
        a->event->event.mouseButton.y >= 500 &&
        a->event->event.mouseButton.y <= 600 && a->nb_wave >= 5) {
            reset_mob_pause(a); a->money->sco = 0; a->var->heart = 100;
            sfText_setString(a->text->score, my_inttostr(a->var->heart));
            a->var->lose = sfFalse;
        }
}

int analyse_event_play_2(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 950 &&
        a->event->event.mouseButton.x <= 1300 &&
        a->event->event.mouseButton.y >= 500 &&
        a->event->event.mouseButton.y <= 600 && a->var->lose == sfTrue) {
            sfRenderWindow_close(a->window->window);
        }
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 550 &&
        a->event->event.mouseButton.x <= 900 &&
        a->event->event.mouseButton.y >= 500 &&
        a->event->event.mouseButton.y <= 600 && a->var->lose == sfTrue) {
            reset_mob_pause(a); a->money->sco = 0; a->var->heart = 100;
            sfText_setString(a->text->score, my_inttostr(a->var->heart));
            a->var->lose = sfFalse;
        }
}

void tower1_interface(global_t* a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 1410 &&
        a->event->event.mouseButton.x <= 1610 &&
        a->event->event.mouseButton.y >= 130 &&
        a->event->event.mouseButton.y <= 330) {
            a->placement = 1;
        }
}

void eventmouse(global_t *a)
{
    sfVector2f click_position, turret_position;
    turret_position.x = a->event->event.mouseButton.x - 50;
    turret_position.y = a->event->event.mouseButton.y - 50;
    tower1_interface(a);
    if (a->placement != 0)
        t1_placement(a, &turret_position);
}

int analyse_events_play(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window->window, &a->event->event)) {
        if (a->event->event.type == sfEvtClosed)
            sfRenderWindow_close(a->window->window);
        if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 33 &&
        a->event->event.mouseButton.x <= 100 &&
        a->event->event.mouseButton.y >= 26 &&
        a->event->event.mouseButton.y <= 104) {
            sfSound_play(a->music->selection); return 1;
        }
        analyse_event_play_2(a); analyse_event_play_3(a);
        if (a->event->event.type == sfEvtKeyPressed &&
        a->event->event.key.code == sfKeySpace) while_open_pause(a);
        if (a->event->event.type == sfEvtMouseButtonPressed) {
            (a->event->event.mouseButton.button == sfMouseLeft &&
            a->nb_t1 < 6) ? eventmouse(a) : 0;
        }
    }
    return 0;
}

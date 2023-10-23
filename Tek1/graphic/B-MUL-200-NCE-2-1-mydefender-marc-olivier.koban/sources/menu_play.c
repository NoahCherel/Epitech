/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu_play
*/

#include "../include/my.h"

void analyse_event_option(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window->window, &a->event->event)) {
        if (a->event->event.type == sfEvtClosed) {
            sfRenderWindow_close(a->window->window);
        }
        if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 1760 &&
        a->event->event.mouseButton.x <= 1900 &&
        a->event->event.mouseButton.y >= 0 &&
        a->event->event.mouseButton.y <= 100) {
            sfSound_play(a->music->selection);
            while_open(a);
        }
        if (a->event->event.type == sfEvtKeyPressed &&
        a->event->event.key.code == sfKeyEscape)
            while_open(a);
    }
}

void option_menu(global_t *a, int c)
{
    if (c == 1) while_open_play(0.05, a);
    if (c == 2) while_open_options(0.05, a);
    if (c == 3) while_open_tutorial(0.05, a);
}

void mouse_menu(global_t *a)
{
    int d = 0;
    if (a->mouse->pos.x >= 1409 && a->mouse->pos.x <= 1734 &&
    a->mouse->pos.y >= 152 && a->mouse->pos.y <= 288) {
        d = 0;
        while (a->menu->selectedItemIndex != 0)
            moveup(a->menu, a->m_button);
    }
    if (a->mouse->pos.x >= 1409 && a->mouse->pos.x <= 1734 &&
    a->mouse->pos.y >= 352 && a->mouse->pos.y <= 588) {
        d = 1;
        if (d > a->menu->selectedItemIndex) {
            movedown(a->menu, a->m_button);
        } else {
            mouse_condition_menu(1, a);
        }
    }
}

void mouse_menu2(global_t *a)
{
    int d = 0;
    if (a->mouse->pos.x >= 1409 && a->mouse->pos.x <= 1734
    && a->mouse->pos.y >= 552 && a->mouse->pos.y <= 788) {
        d = 2;
        if (d < a->menu->selectedItemIndex) {
            moveup(a->menu, a->m_button);
        } else {
            mouse_condition_menu(0, a);
        }
    }
    if (a->mouse->pos.x >= 1409 && a->mouse->pos.x <= 1734 &&
    a->mouse->pos.y >= 752 && a->mouse->pos.y <= 988) {
        d = 3;
        while (a->menu->selectedItemIndex != 3) movedown(a->menu, a->m_button);
    }
}

void mouse_condition_menu(int x, global_t *a)
{
    if (x == 0) {
        while (a->menu->selectedItemIndex != 2) {
            movedown(a->menu, a->m_button);
        }
    }
    if (x == 1) {
        while (a->menu->selectedItemIndex != 1) {
            moveup(a->menu, a->m_button);
        }
    }
}

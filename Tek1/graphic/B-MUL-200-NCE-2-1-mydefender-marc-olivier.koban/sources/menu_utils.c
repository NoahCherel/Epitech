/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu_utils
*/

#include "../include/my.h"

void menu_draw(global_t *a)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(a->window->window, a->menu->menu[i], NULL);
    }
}

void bouton_draw(global_t *a)
{
    sfSprite_setTexture(a->m_button->button[a->menu->selectedItemIndex],
    a->logo->text2, sfFalse);
    sfText_setColor(a->menu->menu[a->menu->selectedItemIndex], sfRed);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(a->window->window,
        a->m_button->button[i], NULL);
    }
}

void moveup(menu_t *menu, menu_button_t *button)
{
    if (menu->selectedItemIndex - 1 >= 0) {
        sfText_setColor(menu->menu[menu->selectedItemIndex], sfWhite);
        menu->selectedItemIndex--;
        sfSprite_setTexture(button->button[menu->selectedItemIndex + 1]
        , button->text, sfFalse);
        sfSprite_setTexture(button->button[menu->selectedItemIndex]
        , menu->hover, sfFalse);
        sfText_setColor(menu->menu[menu->selectedItemIndex], sfRed);
    }
}

void movedown(menu_t *menu, menu_button_t *button)
{
    if (menu->selectedItemIndex + 1 < 4) {
        sfText_setColor(menu->menu[menu->selectedItemIndex], sfWhite);
        menu->selectedItemIndex++;
        sfSprite_setTexture(button->button[menu->selectedItemIndex - 1]
        , button->text, sfFalse);
        sfSprite_setTexture(button->button[menu->selectedItemIndex]
        , menu->hover, sfFalse);
        sfText_setColor(menu->menu[menu->selectedItemIndex], sfRed);
    }
}

int keybord_menu(global_t *a)
{
    switch (a->event->event.type) {
        case sfEvtKeyPressed:
        switch (a->event->event.key.code) {
            case sfKeyUp:
                moveup(a->menu, a->m_button); break;
            case sfKeyDown:
                movedown(a->menu, a->m_button); break;
            case sfKeyEnter:
                sfSound_play(a->music->selection);
                switch (a->menu->selectedItemIndex) {
                    case 0: option_menu(a, 1); break;
                    case 1: option_menu(a, 2); break;
                    case 2: option_menu(a, 3); break;
                    case 3: sfRenderWindow_close(a->window->window);
                }
        }
    }
    return 0;
}

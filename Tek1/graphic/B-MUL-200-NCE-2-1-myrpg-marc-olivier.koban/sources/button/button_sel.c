/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** button_sel
*/

#include "rpg.h"

void sel_bt(button_t *buttons, int i)
{
    buttons[i].sel = 1;
    sfRectangleShape_setOutlineColor(buttons[i].rect, sfRed);
}

void unsel_bt(button_t *buttons, int i)
{
    buttons[i].sel = 0;
    sfRectangleShape_setOutlineColor(buttons[i].rect, sfWhite);
}

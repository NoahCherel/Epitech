/*
** EPITECH PROJECT, 2022
** BUTTON.C
** File description:
** Intialize menu buttons
*/

#include "rpg.h"

void init_button(button_t *button, sfVector2f position, char *text, int sel)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, vect{350, 100});
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    button->text = sfText_create();
    sfText_setString(button->text, text);
    sfText_setFont(button->text, sfFont_createFromFile(D_FONT));
    sfText_setCharacterSize(button->text, 60);
    sfText_setColor(button->text, sfWhite);
    position.x = position.x + (15 - my_strlen(text)) * 3;
    sfText_setPosition(button->text, vect{position.x, position.y + 10});
    button->sel = sel;
    if (sel) sfRectangleShape_setOutlineColor(button->rect, sfRed);
}

void init_buttonsettings(button_t *button, sfVector2f position, char *text)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, vect{100, 100});
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    button->text = sfText_create();
    sfText_setString(button->text, text);
    sfText_setFont(button->text, sfFont_createFromFile(D_FONT));
    sfText_setCharacterSize(button->text, 60);
    sfText_setColor(button->text, sfWhite);
    sfText_setPosition(button->text, vect{position.x + 40, position.y + 10});
}

int button_click(sfRectangleShape *rect, sfVector2i mouse_pos)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    sfVector2f size = sfRectangleShape_getSize(rect);
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x &&
        mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y)
        return (1);
    return (0);
}

int button_is_hovered(sfRectangleShape *rect, sfRenderWindow *window)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    sfVector2f size = sfRectangleShape_getSize(rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x &&
        mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y)
        return (1);
    return (0);
}

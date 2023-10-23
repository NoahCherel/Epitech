/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu
*/

#include "../include/my.h"

title_t *title_setup(title_t *title)
{
    title = malloc(sizeof(title_t));
    sfFont *font = sfFont_createFromFile("sources/font_2.otf");
    title->title = sfSprite_create();
    title->textu = sfTexture_createFromFile("img/menu_background.png", NULL);
    sfSprite_setTexture(title->title, title->textu, sfFalse);
    sfSprite_setPosition(title->title, (sfVector2f){50, 150});
    title->text = sfText_create();
    sfText_setString(title->text, "SPACE DEFENDER");
    sfText_setFont(title->text, font);
    sfText_setColor(title->text, sfWhite);
    sfText_setCharacterSize(title->text, 80);
    sfText_setPosition(title->text, (sfVector2f){225, 275});
    return (title);
}

menu_t *menu_create(menu_t *menu, int i, sfVector2f pos, char *str)
{
    menu->menu[i] = sfText_create();
    sfFont *font = sfFont_createFromFile("sources/font.ttf");
    sfText_setString(menu->menu[i], str);
    sfText_setFont(menu->menu[i], font);
    sfText_setColor(menu->menu[i], sfWhite);
    sfText_setCharacterSize(menu->menu[i], 35);
    sfText_setPosition(menu->menu[i], pos);
}

menu_t *menu(menu_t *menu)
{
    menu = malloc(sizeof(menu_t));
    int selectedItemIndex = 0;
    menu->hover = sfTexture_createFromFile("img/bouton_hover.png", NULL);
    menu_create(menu, 0, (sfVector2f){1500, 200}, "Play");
    menu_create(menu, 1, (sfVector2f){1500, 400}, "Options");
    menu_create(menu, 2, (sfVector2f){1500, 600}, "Tutorial");
    menu_create(menu, 3, (sfVector2f){1500, 800}, "Exit");
    menu->selectedItemIndex = 0;
    return (menu);
}

menu_button_t *button_create(menu_button_t *m_button, int i, sfVector2f pos)
{
    m_button->button[i] = sfSprite_create();
    m_button->text = sfTexture_createFromFile("img/bouton.png", NULL);
    m_button->rect[i].top = 0;
    m_button->rect[i].left = 0;
    m_button->rect[i].width = 350;
    m_button->rect[i].height = 140;
    sfSprite_setTextureRect(m_button->button[i], m_button->rect[i]);
    sfSprite_setTexture(m_button->button[i], m_button->text, sfFalse);
    sfSprite_setPosition(m_button->button[i], pos);
}

menu_button_t *button(menu_button_t *m_button)
{
    m_button = malloc(sizeof(menu_button_t));
    button_create(m_button, 0, (sfVector2f){1450, 150});
    button_create(m_button, 1, (sfVector2f){1450, 350});
    button_create(m_button, 2, (sfVector2f){1450, 550});
    button_create(m_button, 3, (sfVector2f){1450, 750});
    return (m_button);
}

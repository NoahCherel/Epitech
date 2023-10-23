/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** tower_menu
*/

#include "../include/my.h"

tower_menu_t *menu_tower(tower_menu_t* tower, int i, sfVector2f pos)
{
    tower->tower[i] = sfSprite_create();
    tower->text = sfTexture_createFromFile("img/ti.png", NULL);
    tower->rect[i].top = 0;
    tower->rect[i].left = 0;
    tower->rect[i].width = 190;
    tower->rect[i].height = 242;
    sfSprite_setTextureRect(tower->tower[i], tower->rect[i]);
    sfSprite_setTexture(tower->tower[i], tower->text, sfFalse);
    sfSprite_setPosition(tower->tower[i], pos);
}

tower_menu_t *menu_tower1(tower_menu_t* tower, int i, sfVector2f pos, sfVector2f size)
{
    tower->tower_m[i] = sfSprite_create();
    tower->text1 = sfTexture_createFromFile("img/turrets2.png", NULL);
    tower->rect1[i].top = size.x;
    tower->rect1[i].left = size.y;
    tower->rect1[i].width = 160;
    tower->rect1[i].height = 160;
    sfSprite_setTextureRect(tower->tower_m[i], tower->rect1[i]);
    sfSprite_setTexture(tower->tower_m[i], tower->text1, sfFalse);
    sfSprite_setPosition(tower->tower_m[i], pos);
}

tower_menu_t *tower_menu(tower_menu_t *tower)
{
    tower = malloc(sizeof(tower_menu_t));
    tower->selectedItemIndex = 0;
    tower->hover = sfTexture_createFromFile("img/bouton_hover.png", NULL);
    tower_m_create(tower, 0, (sfVector2f){1430, 340}, "Turret");
    tower_m_create(tower, 1, (sfVector2f){1720, 340}, "Ion");
    tower_m_create(tower, 2, (sfVector2f){1430, 640}, "Laser");
    tower_m_create(tower, 3, (sfVector2f){1720, 640}, "Plasma");
    menu_tower(tower, 0, (sfVector2f){1410, 130});
    menu_tower(tower, 1, (sfVector2f){1700, 130});
    menu_tower(tower, 2, (sfVector2f){1410, 430});
    menu_tower(tower, 3, (sfVector2f){1700, 430});
    menu_tower1(tower, 0, (sfVector2f){1420, 140}, (sfVector2f){0, 0});
    menu_tower1(tower, 1, (sfVector2f){1420, 440}, (sfVector2f){160, 0});
    menu_tower1(tower, 2, (sfVector2f){1720, 140}, (sfVector2f){0, 160});
    menu_tower1(tower, 3, (sfVector2f){1720, 440}, (sfVector2f){0, 320});
    return (tower);
}

tower_menu_t *tower_m_create(tower_menu_t *menu, int i, sfVector2f pos,
char *str)
{
    sfFont *font = sfFont_createFromFile("sources/font.ttf");
    menu->menu[i] = sfText_create();
    sfText_setString(menu->menu[i], str);
    sfText_setFont(menu->menu[i], font);
    sfText_setColor(menu->menu[i], sfBlack);
    sfText_setCharacterSize(menu->menu[i], 25);
    sfText_setPosition(menu->menu[i], pos);
}

void tower_draw(global_t *a)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(a->window->window, a->tower->tower[i], NULL);
        sfRenderWindow_drawText(a->window->window, a->tower->menu[i], NULL);
    }
    for (int j = 0; j < 4; j++) {
        sfRenderWindow_drawSprite(a->window->window, a->tower->tower_m[j],
        NULL);
    }
}

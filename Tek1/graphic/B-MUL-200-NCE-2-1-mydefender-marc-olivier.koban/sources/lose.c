/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** lose
*/

#include "../include/my.h"

lose_t *lost(lose_t *a)
{
    a = malloc(sizeof(lose_t));
    sfFont *font = sfFont_createFromFile("sources/font.ttf");
    a->lose1 = sfSprite_create(); a->play = sfSprite_create();
    a->text1 = sfTexture_createFromFile("img/test.png", NULL);
    a->lose = sfSprite_create(); a->text2 = sfText_create();
    a->text = sfTexture_createFromFile("img/quit_lose.jpg", NULL);
    a->text3 = sfTexture_createFromFile("img/play_lose.jpg", NULL);
    sfText_setString(a->text2, "MISSION FAILED, BETTER LUCK NEXT TIME");
    sfText_setFont(a->text2, font); sfText_setColor(a->text2, sfRed);
    sfText_setCharacterSize(a->text2, 23);
    sfSprite_setTexture(a->lose1, a->text1, sfFalse);
    sfSprite_setTexture(a->lose, a->text, sfFalse);
    sfSprite_setTexture(a->play, a->text3, sfFalse);
    sfSprite_setPosition(a->lose1, (sfVector2f){500, 300});
    sfSprite_setPosition(a->play, (sfVector2f){550, 450});
    sfSprite_setPosition(a->lose, (sfVector2f){950, 450});
    sfText_setPosition(a->text2, (sfVector2f){530, 380});
    return (a);
}

void lose(global_t *a)
{
    sfRenderWindow_drawSprite(a->window->window, a->lose->lose1, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->lose->lose, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->lose->play, NULL);
    sfRenderWindow_drawText(a->window->window, a->lose->text2, NULL);
}

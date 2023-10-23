/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** utils
*/

#include "../include/my.h"

void my_help(int ac, char **av)
{
    if (av[1][0] == 'h' || av[1][1] == 'h') {
        my_putstr("My hunter : Epitech Project where the goal is to shoot");
        my_putchar(' ');
        my_putstr("pokemon to complete your pokedex with your mouse cursor");
        my_putchar('\n');
    }
}

void set_text(sfSprite *Bird, sfTexture *text_Bird, sfIntRect rect)
{
    sfSprite_setTexture(Bird, text_Bird, sfFalse);
    sfSprite_setTextureRect(Bird, rect);
}

void set_text2(sfSprite *Bird, sfTexture *text_Bird, sfIntRect rect)
{
    sfSprite_setTexture(Bird, text_Bird, sfFalse);
    sfSprite_setTextureRect(Bird, rect);
}

void score_fct(sfRenderWindow *window, sfClock *clock, int score2)
{
    sfVector2f ps = {150, 0};
    sfText *score = sfText_create(); sfText *score1 = sfText_create();
    sfText_setString(score, my_inttostr(score2));
    sfText_setString(score1 ,"Score:"); sfText_setPosition(score, ps);
    sfFont *Font = sfFont_createFromFile("font1.ttf");
    sfText_setFont(score, Font); sfText_setFont(score1, Font);
    sfRenderWindow_drawText(window, score1, NULL);
    sfRenderWindow_drawText(window, score, NULL);
}

void free_all(global_t *a)
{
    free(a->background);
    free(a->clo);
    free(a->bird);
    free(a->cursor);
    free(a);
}

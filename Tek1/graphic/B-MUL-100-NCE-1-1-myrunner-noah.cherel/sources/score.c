/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** score
*/

#include "../include/my.h"

score_t *score_init(score_t *score1)
{
    score1 = malloc(sizeof(score_t));
    score1->sco = 0;
    return (score1);
}

void score_fct(sfRenderWindow *window, int score2)
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

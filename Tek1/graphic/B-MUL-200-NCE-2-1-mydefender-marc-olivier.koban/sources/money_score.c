/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** money_score
*/

#include "../include/my.h"

score_t *score_init(score_t *score)
{
    score = malloc(sizeof(score_t)); score->text = sfText_create();
    score->money_s = sfSprite_create(); score->money = 100; score->sco = 0;
    score->money_t = sfTexture_createFromFile("img/money_icon.png", NULL);
    sfText_setPosition(score->text, (sfVector2f){1460, 910});
    sfSprite_setTexture(score->money_s, score->money_t, sfFalse);
    sfSprite_setPosition(score->money_s, (sfVector2f){1405, 910});
    sfText_setString(score->text, my_inttostr(score->money));
    sfFont *font = sfFont_createFromFile("sources/font.ttf");
    sfText_setFont(score->text, font); sfText_setColor(score->text, sfWhite);
    sfText_setCharacterSize(score->text, 50);
    sfVector2f ps = {150, 150}; sfVector2f ps1 = {0, 150};
    score->score = sfText_create(); score->score1 = sfText_create();
    sfText_setString(score->score, my_inttostr(score->sco));
    sfText_setString(score->score1 ,"Score:");
    sfText_setPosition(score->score1, ps1);
    sfText_setPosition(score->score, ps);
    sfText_setFont(score->score, font); sfText_setFont(score->score1, font);
    return (score);
}

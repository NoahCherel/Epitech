/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** pathfinding
*/

#include "../include/my.h"

char *set_path(global_t *a)
{
    int y, x; char b; char *str1 = malloc(sizeof(char*) * 64);
    char *str = malloc(sizeof(char*) * 64); int i1dIndex = 0, index = 0;
    for (int iOuter = 0; iOuter < 13; iOuter++) {
        for (int iInner = 0; iInner < 7; iInner++)
            str1[i1dIndex] = a->map->map_2d[iOuter][iInner]; i1dIndex++;
    }
    for (int a = 0; a < (13 * 8); a++) {
        if (str1[a] == '8') {
                str[index] = '7'; index++;
            }
        if (str1[a] == '7') {
                str[index] = '8'; index++;
            }
        if (str1[a] != '4' && str1[a] != '3' && str1[a] != 'a' &&
        str1[a] != '1' && str1[a] != '8' && str1[a] != '7') {
            str[index] = str1[a];
            index ++;
        }
    }
    return (str);
}

void path_x(global_t *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if ((a->enemy1[i].xy.x < 210) || (a->enemy1[i].xy.x == 210 &&
        a->enemy1[i].xy.y == 500)
        || (a->enemy1[i].xy.y == 730 && a->enemy1[i].xy.x < 510)
        || (a->enemy1[i].xy.y == 430 && a->enemy1[i].xy.x != 710)
        || (a->enemy1[i].xy.y == 640 && a->enemy1[i].xy.x != 920 &&
        a->enemy1[i].xy.x > 600)
        || (a->enemy1[i].xy.y == 540 && a->enemy1[i].xy.x != 1120 &&
        a->enemy1[i].xy.x > 800)) {
            a->enemy1[i].frame.left = 75;
            sfSprite_setTextureRect(a->enemy1[i].sprite, a->enemy1[i].frame);
            a->enemy1[i].xy.x += 1;
        }
    }
}

void path_y(global_t *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if ((a->enemy1[i].xy.x == 510 && a->enemy1[i].xy.y != 430)
        || (a->enemy1[i].xy.x == 920 && a->enemy1[i].xy.y != 540)) {
            a->enemy1[i].frame.left = 150;
            sfSprite_setTextureRect(a->enemy1[i].sprite, a->enemy1[i].frame);
            a->enemy1[i].xy.y += -1;
        }
        if ((a->enemy1[i].xy.y != 730 && a->enemy1[i].xy.x == 210)
        || (a->enemy1[i].xy.x == 710 && a->enemy1[i].xy.y != 640)
        || (a->enemy1[i].xy.x == 1120 && a->enemy1[i].xy.y != 640)) {
            a->enemy1[i].frame.left = 0;
            sfSprite_setTextureRect(a->enemy1[i].sprite, a->enemy1[i].frame);
            a->enemy1[i].xy.y += 1;
        }
    }
}

int enemy_move(global_t *a)
{
    for (int i = 0; i < a->nb_enemy1; i++) {
        path_x(a);
        path_y(a);
        if (a->var->lose == sfFalse)
            a->money->sco += 1;
        sfText_setString(a->money->score, my_inttostr(a->money->sco));
        if (a->enemy1[i].xy.x > 1200 && a->var->heart == 0) {
            a->var->lose = sfTrue;
            return (0);
        }
        if (a->enemy1[i].xy.x > 1200) {
            a->var->heart -= 1;
            sfText_setString(a->text->score, my_inttostr(a->var->heart));
        }
        sfSprite_setPosition(a->enemy1[i].sprite, a->enemy1[i].xy);
    }
}

void pathfinding(global_t *a)
{
    enemy_move(a);
}

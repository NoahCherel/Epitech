/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** seetings2.c
*/

#include "rpg.h"

int set_box(scene_t *scene, int i, global_t *g)
{
    if (i == 7 && g->textbox < 15) {
        g->textbox += 1; scene->rects->rect.top += 300;
        sfSprite_setTextureRect(scene->rects->sprite, scene->rects->rect);
        g->rects[0].rect.top = g->textbox * 300; 
        sfSprite_setTextureRect(g->rects->sprite, g->rects->rect);
        return (1);
    }
    if (i == 6 && g->textbox > 0) {
        g->textbox -= 1; scene->rects->rect.top -= 300;
        sfSprite_setTextureRect(scene->rects->sprite, scene->rects->rect);
        g->rects[0].rect.top = g->textbox * 300;
        sfSprite_setTextureRect(g->rects->sprite, g->rects->rect);
        return (1);
    }
    if (i == 9 && g->font < 4) {
        g->font += 1, change_text(scene, g); return (1);
    }
    if (i == 8 && g->font > 0) {
        g->font -= 1, change_text(scene, g); return (1);
    }
    if (i >= 6 && i <= 9) return (0);
}

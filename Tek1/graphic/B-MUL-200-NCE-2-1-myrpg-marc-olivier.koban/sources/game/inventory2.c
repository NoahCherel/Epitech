/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** inventory2
*/

#include "rpg.h"

void close_btn_inv(scene_t *scene, global_t *g)
{
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        scene->inventory = 0;
}

void coininv(scene_t *scene, global_t *g)
{
    scene->nb_textscoin = 1;
    scene->textscoin = malloc(sizeof(sfText *) * scene->nb_textscoin + 1);
    scene->spritecoin = sfSprite_create();
    scene->texturecoin = sfTexture_createFromFile("img/coin.png", NULL);
    sfSprite_setTexture(scene->spritecoin, scene->texturecoin, sfTrue);
    sfSprite_setPosition(scene->spritecoin, vect{1920 - 390, 76});
    sfSprite_setScale(scene->spritecoin, vect{0.09, 0.09});
    scene->textscoin[0] = txt2(vect{1580, 91}, 20 , intoa(g->st->money), FONT);
}

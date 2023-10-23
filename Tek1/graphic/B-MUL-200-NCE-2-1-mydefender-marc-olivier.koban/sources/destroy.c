/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** destroy
*/

#include "../include/my.h"

void destroy_all2(global_t *a)
{
    sfSprite_destroy(a->lose->lose);
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(a->m_button->button[i]);
        sfSprite_destroy(a->tower->tower[i]);
        sfSprite_destroy(a->tower->tower_m[i]);
    }
    sfTexture_destroy(a->m_button->text);
    sfSprite_destroy(a->map->tile);
    sfTexture_destroy(a->map->tiletext);
    sfTexture_destroy(a->menu->hover);
    for (int i = 0; i < 6; i++) {
        sfSprite_destroy(a->tower1[i].sprite);
        sfTexture_destroy(a->tower1[i].texture);
    }
}

void destroy_all1(global_t *a)
{
    sfSprite_destroy(a->money->money_s);
    sfTexture_destroy(a->money->money_t);
    sfSprite_destroy(a->mouse->cursor);
    sfTexture_destroy(a->mouse->text);
    sfSprite_destroy(a->sprite->back);
    sfSprite_destroy(a->sprite->button_menu);
    sfSprite_destroy(a->sprite->image_menu);
    sfSprite_destroy(a->sprite->life);
    sfSprite_destroy(a->sprite->pause);
    sfSprite_destroy(a->sprite->play);
    sfSprite_destroy(a->sprite->quit);
    sfSprite_destroy(a->sprite->sound_off);
    sfSprite_destroy(a->sprite->sound_on);
    sfSprite_destroy(a->title->title);
    sfTexture_destroy(a->title->textu);
    sfTexture_destroy(a->tower->hover);
    sfTexture_destroy(a->tower->text1);
    sfTexture_destroy(a->tower->text);
}

void destroy_all(global_t *a)
{
    sfMusic_destroy(a->music->music_game);
    sfMusic_destroy(a->music->music_menu);
    sfSound_destroy(a->music->selection);
    sfSoundBuffer_destroy(a->music->select);
    sfSprite_destroy(a->hud->money); sfSprite_destroy(a->hud->tower);
    for (int i = 0; i < 100; i++) {
        sfSprite_destroy(a->enemy1[i].sprite);
        sfTexture_destroy(a->enemy1[i].texture);
    }
    sfTexture_destroy(a->hud->text);
    sfTexture_destroy(a->hud->text1);
    sfSprite_destroy(a->logo->logo);
    sfTexture_destroy(a->logo->text);
    sfTexture_destroy(a->logo->text2);
    sfSprite_destroy(a->lose->lose1);
    sfTexture_destroy(a->lose->text);
    sfTexture_destroy(a->lose->text1);
    destroy_all2(a); destroy_all1(a);
    sfRenderWindow_destroy(a->window->window);
}

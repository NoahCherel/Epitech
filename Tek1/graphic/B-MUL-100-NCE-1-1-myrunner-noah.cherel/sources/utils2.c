/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** utils2
*/

#include "../include/my.h"

void pause_funct(global_t *a)
{
    sfVector2f ps = {800, 400};
    sfText *pause = sfText_create();
    sfText *pause1 = sfText_create();
    sfText_setString(pause ,"PAUSE");
    sfText_setString(pause1 ,"WIN");
    sfFont *Font = sfFont_createFromFile("font1.ttf");
    sfText_setPosition(pause, ps);
    sfText_setPosition(pause1, ps);
    sfText_setFont(pause, Font);
    sfText_setFont(pause1, Font);
    if (a->clo->win == sfTrue) {
        sfRenderWindow_drawText(a->window, pause1, NULL);
        a->clo->pause = sfTrue;
    }
    else if (a->clo->pause == sfTrue)
        sfRenderWindow_drawText(a->window, pause, NULL);
}

void dead_funct(global_t *a)
{
    sfVector2f ps = {800, 400};
    sfText *dead = sfText_create();
    sfText_setString(dead ,"DEAD");
    sfFont *Font = sfFont_createFromFile("font1.ttf");
    sfText_setPosition(dead, ps);
    sfText_setFont(dead, Font);
    if (a->c->d == sfTrue) {
        sfRenderWindow_drawText(a->window, dead, NULL);
        a->clo->pause == sfTrue;
    }
}

void set_sound(sounds_t *sounds)
{
    sounds = malloc(sizeof(sounds_t));
    sounds->buffer = sfSoundBuffer_createFromFile("pause.ogg");
    sounds->sound = sfSound_create();
    sfSound_setBuffer(sounds->sound, sounds->buffer);
    sfSound_setVolume(sounds->sound, 100);
    sfSound_play(sounds->sound);
}

void destroy_all(global_t *a)
{
    sfSprite_destroy(a->p->back);
    sfSprite_destroy(a->p->far);
    sfSprite_destroy(a->p->Forefront);
    sfSprite_destroy(a->c->sprite);
    sfTexture_destroy(a->c->texture);
    sfSprite_destroy(a->g->c->s);
    sfTexture_destroy(a->g->c->text);
    sfSprite_destroy(a->g->c->s);
    sfSprite_destroy(a->g->monster->m);
    sfTexture_destroy(a->g->monster->text);
}

void free_all(global_t *a)
{
    free(a->c);
    free(a->clo);
    free(a->g);
    free(a->j);
    free(a->p);
    free(a->score1);
    free(a->sounds);
    free(a);
}

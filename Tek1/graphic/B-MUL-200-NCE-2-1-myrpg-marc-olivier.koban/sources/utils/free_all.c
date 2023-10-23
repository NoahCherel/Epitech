/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** free_all
*/

#include "rpg.h"

void free_all(scene_t **scenes, global_t *g)
{
    sfMusic_destroy(g->music->music_menu);
    sfMusic_destroy(g->music->music_game);
    sfMusic_destroy(g->music->music_battle);
    sfSound_destroy(g->music->sound);
    sfSoundBuffer_destroy(g->music->soundbuf);
    for (int i = 0; i < 10; i++) {
        free(scenes[i]);
    }
    free(g->window); free(g->music); free(g->st);
    free(g->quest); free(g); free(scenes);
}

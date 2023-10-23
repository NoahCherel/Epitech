/*
** EPITECH PROJECT, 2022
** MY RPG : SOUND.C
** File description:
** sound
*/

#include "rpg.h"

music_t *init_music(global_t *g)
{
    music_t *music = malloc(sizeof(music_t));
    g->vol = 20;
    music->music_game = sfMusic_createFromFile("sounds/game_music.ogg");
    music->music_menu = sfMusic_createFromFile("sounds/menu_music.ogg");
    music->music_battle = sfMusic_createFromFile("sounds/battle_music.ogg");
    music->soundbuf = sfSoundBuffer_createFromFile("sounds/buffer.ogg");
    music->sound = sfSound_create();
    sfSound_setBuffer(music->sound, music->soundbuf);
    sfMusic_setVolume(music->music_game, g->vol);
    sfMusic_setVolume(music->music_menu, g->vol);
    sfMusic_setVolume(music->music_battle, g->vol);
    sfMusic_setLoop(music->music_menu, sfTrue);
    sfMusic_setLoop(music->music_game, sfTrue);
    sfMusic_setLoop(music->music_battle, sfTrue);
    return (music);
}

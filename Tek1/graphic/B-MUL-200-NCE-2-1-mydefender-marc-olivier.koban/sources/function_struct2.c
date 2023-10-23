/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** function_struct2.c my_defender
*/

#include "../include/my.h"

music_t *creation_music(music_t *music)
{
    music = malloc(sizeof(music_t));
    music->music_menu = sfMusic_createFromFile("sources/music_menu1.ogg");
    music->select = sfSoundBuffer_createFromFile("sources/a.ogg");
    music->music_game = sfMusic_createFromFile("sources/music_game1.ogg");
    sfMusic_setLoop(music->music_menu, sfTrue);
    sfMusic_setLoop(music->music_game, sfTrue);
    sfMusic_setVolume(music->music_menu, 50);
    sfMusic_setVolume(music->music_game, 50);
    music->selection = sfSound_create();
    sfSound_setBuffer(music->selection, music->select);
    sfSound_setVolume(music->selection, 100);
    return (music);
}

clocks_t *set_clock(clocks_t *cl)
{
    cl = malloc(sizeof(clocks_t));
    cl->para = sfClock_create();
    return (cl);
}

time12_u *set_time(time12_u *time1)
{
    time1 = malloc(sizeof(time12_u));
    return time1;
}

pos_t *set_pos(pos_t *pos_fond)
{
    pos_fond = malloc(sizeof(pos_t));
    pos_fond->pos_sound.x = 850;
    pos_fond->pos_sound.y = 500;
    pos_fond->pos_back.x = 0;
    pos_fond->pos_back.y = 890;
    pos_fond->menu_hard1.x = 300;
    pos_fond->menu_hard1.y = 200;
    pos_fond->menu_hard1.x = 500;
    pos_fond->menu_hard1.y = 200;
    return (pos_fond);
}

logo_t *logo_display(logo_t *a)
{
    a = malloc(sizeof(logo_t));
    a->logo = sfSprite_create();
    a->text = sfTexture_createFromFile("img/logo.png", NULL);
    a->text2 = sfTexture_createFromFile("img/bouton_hover.png", NULL);
    sfSprite_setTexture(a->logo, a->text, sfFalse);
    sfSprite_setPosition(a->logo, (sfVector2f){350, 300});
    return (a);
}

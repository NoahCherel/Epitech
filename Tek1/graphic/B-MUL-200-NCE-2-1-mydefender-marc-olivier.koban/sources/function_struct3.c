/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** function_struct3.c
*/

#include "../include/my.h"

var_t *set_var(var_t *var)
{
    var = malloc(sizeof(var_t));
    var->heart = 100;
    var->lose = sfFalse;
    return (var);
}

text_t *set_text(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->score = sfText_create(); text->fps_30 = sfText_create();
    text->fps_60 = sfText_create(); text->fps_120 = sfText_create();
    text->font = sfFont_createFromFile("sources/font.ttf");
    sfText_setString(text->fps_30, "30"); sfText_setString(text->fps_60, "60");
    sfText_setString(text->fps_120, "120");
    sfText_setFont(text->fps_30, text->font);
    sfText_setFont(text->fps_60, text->font);
    sfText_setFont(text->fps_120, text->font);
    sfText_setColor(text->score, sfWhite);
    sfText_setColor(text->fps_30, sfWhite);
    sfText_setColor(text->fps_60, sfRed);
    sfText_setColor(text->fps_120, sfWhite);
    sfText_setCharacterSize(text->fps_30, 50);
    sfText_setCharacterSize(text->fps_60, 50);
    sfText_setCharacterSize(text->fps_120, 50);
    return (text);
}

void *set_sprite4(sprite2_t *sprite2)
{
    sfTexture *test = sfTexture_createFromFile("img/fps.jpeg", NULL);
    sfSprite_setTexture(sprite2->test, test, sfFalse);
}

sprite2_t *set_sprite3(sprite2_t *sprite2)
{
    sprite2 = malloc(sizeof(sprite_t));
    sprite2->test = sfSprite_create();
    set_sprite4(sprite2);
    return (sprite2);
}

hud_play_t *hud_init(hud_play_t *a)
{
    a = malloc(sizeof(hud_play_t));
    a->tower = sfSprite_create();
    a->text = sfTexture_createFromFile("img/menu.png", NULL);
    sfSprite_setTexture(a->tower, a->text, sfFalse);
    sfSprite_setPosition(a->tower, (sfVector2f){1380, 100});
    a->money = sfSprite_create();
    a->text1 = sfTexture_createFromFile("img/money.png", NULL);
    sfSprite_setTexture(a->money, a->text1, sfFalse);
    sfSprite_setPosition(a->money, (sfVector2f){1400, 900});
    return (a);
}

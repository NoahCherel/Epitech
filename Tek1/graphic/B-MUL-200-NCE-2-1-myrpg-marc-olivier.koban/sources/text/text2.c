/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** text2.c
*/

#include "rpg.h"

sfText *init_txt_gain(sfVector2f pos, sfVector2f size_gain, char *font, int ty)
{
    sfText *txt = sfText_create();
    char *text = "You just got : ";
    int len = my_strlen(text); char *a = malloc(sizeof(char) * (len + 1));
    for (int x = 0; x < len; x++) a[x] = text[x]; a[len] = '\0';
    char *number = my_inttostr(size_gain.y); int len2 = my_strlen(number);
    char *string2 = malloc(sizeof(char *) * (len + len2 + 1));
    string2 = my_strcat(a, number);
    char *string3 = malloc(sizeof(char *) * (len + len2 + 7));
    if (ty == 0) string3 = my_strcat(string2, " COINS");
    if (ty == 1) string3 = my_strcat(string2, " EXP");
    sfText_setString(txt, string3);
    sfText_setFont(txt, sfFont_createFromFile(font));
    sfText_setCharacterSize(txt, size_gain.x);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    return (txt);
}

sfBool chest_text(sfVector2f choice_gain, sfBool a, global_t *g, int bonus)
{
    if (g->text_choice2 == 0) {
        if (a == sfTrue) {
            g->text_choice2 = choice_gain.y; g->text_choice = choice_gain.y;
        } else {
            g->text_choice2 = choice_gain.x; g->text_choice = choice_gain.x;
            g->st->money += bonus; a = sfTrue;
        }
    } else {
        g->text_choice2 = 0; g->text_choice = 0;
    }
    return (a);
}

sfBool double_text_exp(sfVector2f choice_gain, sfBool a, global_t *g, int bon)
{
    if (g->text_choice2 == 0 || a != sfTrue) {
        if (g->text_choice2 != 0 && a != sfTrue) {
            g->text_choice2 = choice_gain.y; g->text_choice = choice_gain.y;
            g->st->exp += bon; a = sfTrue;
        } else {
            g->text_choice2 = choice_gain.x; g->text_choice = choice_gain.x;
        }
    } else {
        g->text_choice2 = 0; g->text_choice = 0;
    }
    return (a);
}

sfBool double_text_coins(sfVector2f c_gain, sfBool a, global_t *g, int bon)
{
    if (g->text_choice2 == 0 || a != sfTrue) {
        if (g->text_choice2 != 0 && a != sfTrue) {
            g->text_choice2 = c_gain.y; g->text_choice = c_gain.y;
            g->st->money += bon; a = sfTrue;
        } else {
            g->text_choice2 = c_gain.x; g->text_choice = c_gain.x;
        }
    } else {
        g->text_choice2 = 0; g->text_choice = 0;
    }
    return (a);
}

void simple_text(int text_choice, global_t *g)
{
    if (g->text_choice2 == text_choice) {
        g->text_choice2 = 0; g->text_choice = 0;
    } else {
        g->text_choice2 = text_choice; g->text_choice = text_choice;
    }
}

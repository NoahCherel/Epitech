/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** events2.c
*/

#include "rpg.h"

void choice_text(global_t *g)
{
    g->i = 0;
    if (g->pos_player.x >= 864 && g->pos_player.x <= 908 &&
    g->pos_player.y == 472 && g->head == 1) {
        if (g->text_choice == 1) g->text_choice = 0;
        else {
            g->text_choice = 1;
        }
    }
    if (g->pos_player.x >= 756 && g->pos_player.x <= 780 &&
    g->pos_player.y == 456 && g->head == 1 || g->pos_player.x == 780 &&
    g->pos_player.y <= 456 && g->pos_player.y >= 440 && g->head == 3) {
        if (g->text_choice == 2) g->text_choice = 0;
        else {
            g->text_choice = 2;
        }
    }
}

void choice_text_2(global_t *g)
{
    g->i = 0;
    if (g->pos_player.x >= 864 && g->pos_player.x <= 868 &&
    g->pos_player.y == 504 && g->head == 1)
        g->text_choice = g->text_choice == 1 ? 0 : 1;
    if (X_BTW(832, 840) && g->pos_player.y == 412 && g->head == 1)
        g->text_choice = g->text_choice == 2 ? 0 : 2;
    if (g->pos_player.x >= 764 && g->pos_player.x <= 776 &&
    g->pos_player.y == 440 && g->head == 1 || g->pos_player.x == 788 &&
    g->pos_player.y <= 432 && g->pos_player.y >= 420 && g->head == 3 ||
    g->pos_player.x == 748 && g->pos_player.y >= 420 &&
    g->pos_player.y <= 432 && g->head == 2)
        g->text_choice = g->text_choice == 3 ? 0 : 3;
    if (X_BTW(1248, 1256) && g->pos_player.y >= 480)
        g->text_choice = g->text_choice == 4 ? 0 : 4;
    if (X_BTW(956, 968) && g->pos_player.y == 816 && g->head == 1)
        g->text_choice = g->text_choice == 5 ? 0 : 5;
    if (X_BTW(1120, 1132) && g->pos_player.y == 816 && g->head == 1)
        g->text_choice = g->text_choice == 6 ? 0 : 6;
    choice_text_2_2(g);
}

void init_text_game(scene_t *scene, global_t *g)
{
    ftext = init_txt(vect{150, 775}, 50,
    "The N-Air of Wario starts at frame 4 !", FONT);
    scene->texts[1] = init_txt(vect{150, 775}, 50, "Glou, glou...", FONT);
}

void init_text_map_main(scene_t *scene, global_t *g)
{
    ftext = init_txt(vect{150, 775}, 50,
    "If you press 'A', you can see your stats !", FONT);
    scene->texts[1] = init_txt(vect{150, 775}, 50,
    "Here lies little Gregory...", FONT);
    scene->texts[2] = init_txt(vect{150, 775}, 50,
    "My son died 38 years ago...\nNow I pray everyday for him...", FONT);
    scene->texts[3] = init_txt(vect{150, 775}, 50, "It's closed !", FONT);
    scene->texts[4] = init_txt(vect{150, 775}, 50, "Justin's Pub", FONT);
    scene->texts[5] = init_txt(vect{150, 775}, 50, "Sword Shop", FONT);
    scene->texts[6] = init_txt(vect{150, 775}, 50,
    "What do you want ? Leave me alone !", FONT);
    scene->texts[7] = init_txt(vect{150, 775}, 50, "How did you find me ??",
    FONT);
}

int event_text(global_t *g, int i)
{
    if (WINDOW->event.type == sfEvtKeyReleased &&
    KEYCODE == sfKeyE) {
        switch (i) {
            case 1: choice_text(g); break;
            case 2: choice_text_2(g); break;
            case 3: interaction_npc(g); break;
            case 4:
                if (g->quest->is_active != sfTrue)
                    interaction_quest(g);
                if (g->quest->is_active == sfTrue && g->beat_boss == sfFalse)
                    reminder_quest(g);
                if (g->quest->is_active == sfTrue && g->beat_boss == sfTrue)
                    return (end_quest(g));
                break;
            case 5: choice_text_3(g); break;
        }
    } return (0);
}

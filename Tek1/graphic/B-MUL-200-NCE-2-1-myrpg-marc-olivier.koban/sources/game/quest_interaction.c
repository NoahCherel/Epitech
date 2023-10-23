/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** quest_interaction
*/

#include "rpg.h"

void interaction_quest(global_t *g)
{
    if (X_BTW(872, 888) && Y_BTW(340, 348) && g->head == 1) {
        if (g->quest->quest_choice == 1) {
            g->text_choice = 0;
            g->quest->quest_choice = 0;
            g->statu_menu = 0;
            g->quest->quest_pnj_menu = 0;
        } else {
            g->text_choice = 1;
            g->quest->quest_choice = 1;
            g->statu_menu = 1;
            g->quest->quest_pnj_menu = 1;
        }
    } else {
        g->quest->quest_pnj_menu = 0;
    }
}

void reminder_quest(global_t *g)
{
    if (X_BTW(872, 888) && Y_BTW(340, 348) && g->head == 1) {
        if (g->quest->reminder == 1) {
            g->text_choice = 0;
            g->quest->quest_choice = 0;
            g->statu_menu = 0;
            g->quest->reminder = 0;
        } else {
            g->text_choice = 1;
            g->quest->quest_choice = 1;
            g->statu_menu = 1;
            g->quest->reminder = 1;
        }
    } else {
        g->quest->reminder = 0;
    }
}

int end_quest(global_t *g)
{
    if (X_BTW(872, 888) && Y_BTW(340, 348) && g->head == 1) {
        if (g->quest->end_quest == 1) {
            g->text_choice = 0;
            g->quest->quest_choice = 0;
            g->statu_menu = 0;
            g->quest->end_quest = 0;
            return (10);
        } else {
            g->text_choice = 1;
            g->quest->quest_choice = 1;
            g->statu_menu = 1;
            g->quest->end_quest = 1;
        }
    } else {
        g->quest->end_quest = 0;
    }
    return (0);
}

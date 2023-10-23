/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** materials
*/

#include "../inc/server.h"

#include <stdlib.h>
#include <time.h>

void place_food(game_t *game, float food_quantity)
{
    int num_food = (int)food_quantity;
    int food_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_food;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].food++;
        food_placed++;
    }
}

void place_linemate(game_t *game, float linemate_quantity)
{
    int num_linemate = (int)linemate_quantity;
    int linemate_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_linemate;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].linemate++;
        linemate_placed++;
    }
}

void place_deraumere(game_t *game, float deraumere_quantity)
{
    int num_deraumere = (int)deraumere_quantity;
    int deraumere_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_deraumere;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].deraumere++;
        deraumere_placed++;
    }
}

void place_sibur(game_t *game, float sibur_quantity)
{
    int num_sibur = (int)sibur_quantity;
    int sibur_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_sibur;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].sibur++;
        sibur_placed++;
    }
}

void place_mendiane(game_t *game, float mendiane_quantity)
{
    int num_mendiane = (int)mendiane_quantity;
    int mendiane_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_mendiane;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].mendiane++;
        mendiane_placed++;
    }
}

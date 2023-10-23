/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** materials
*/

#include "../inc/server.h"

void place_phiras(game_t *game, float phiras_quantity)
{
    int num_phiras = (int)phiras_quantity;
    int phiras_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_phiras;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].phiras++;
        phiras_placed++;
    }
}

void place_thystame(game_t *game, float thystame_quantity)
{
    int num_thystame = (int)thystame_quantity;
    int thystame_placed = 0;
    int i, j;
    srand(rand());
    int cells_to_place = num_thystame;
    for (int k = 0; k < cells_to_place; k++) {
        i = rand() % game->height;
        j = rand() % game->width;
        game->map[i][j].thystame++;
        thystame_placed++;
    }
}

void place_materials(game_t *game)
{
    int total_cells = game->width * game->height;
    float food_quantity = total_cells * 0.5;
    float linemate_quantity = total_cells * 0.3;
    float deraumere_quantity = total_cells * 0.15;
    float sibur_quantity = total_cells * 0.1;
    float mendiane_quantity = total_cells * 0.1;
    float phiras_quantity = total_cells * 0.08;
    float thystame_quantity = total_cells * 0.05;

    place_food(game, food_quantity);
    place_linemate(game, linemate_quantity);
    place_deraumere(game, deraumere_quantity);
    place_sibur(game, sibur_quantity);
    place_mendiane(game, mendiane_quantity);
    place_phiras(game, phiras_quantity);
    place_thystame(game, thystame_quantity);
}

void update_resources(game_t *game)
{
    if (get_current_time() >= game->materials_timer) {
        game->materials_timer = 20 + get_current_time();
        place_materials(game);
        printf("Materials updated\n");
    }
}

void update_players(game_t *game)
{
    if (get_current_time() >= game->players_timer) {
        game->players_timer = (126 / game->freq) + get_current_time();
            for (int j = 0; j < game->teamsNb; j++) {
                for (int i = 0; i < game->num_players; i++) {
                    if (game->teams[j].players[i].inventory.food > 0 ) {
                        game->teams[j].players[i].inventory.food--;
                    } else {
                        send (game->teams[j].players[i].sockfd, "dead\n", 5, 0);
                        send (game->graphicSockfd, "pdi %d\n", 5, game->teams[j].players[i].id);
                    }
                }
            }
        printf("Players updated\n");
    }
}

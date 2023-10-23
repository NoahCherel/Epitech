/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** handle_commands
*/

#include "../inc/server.h"

void handle_tna(int sockfd, game_t *game)
{
    send_team_names(sockfd, game);
}

void handle_pnw(int sockfd, game_t *game, int playerId)
{
    for (int i = 0; i < game->teamsNb; i++) {
        for (int j = 0; j < game->num_players; j++) {
            if (game->teams[i].players[j].id == playerId) {
                printf("game->teams[%d].players[%d].id = %d\n", i, j,
                game->teams[i].players[j].id);
                send_connection_new_player(sockfd, &game->teams[i].players[j]);
                return;
            }
        }
    }
    printf("Error: Player with id %d not found\n", playerId);
}

void handle_plv(int sockfd, game_t *game)
{
    send_player_level(sockfd, game, game->playerId);
}

void handle_ppo(int sockfd, game_t *game)
{
    send_player_pos(sockfd, game, game->playerId);
}

void handle_pin(int sockfd, game_t *game)
{
    send_player_inventory(sockfd, game, game->playerId);
}
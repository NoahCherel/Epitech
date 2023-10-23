/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** elevation
*/

#include "../inc/server.h"

void handle_incantation_function(int sockfd, game_t *game, int id)
{
    char response[1024]; send(sockfd, "Elevation underway\n", 19, 0);
    Player *player = get_player_by_id(game, id);
    int playerLevel = player->level; int X = player->pos.x;
    int Y = player->pos.y; int nb = game->map[Y][X].players;
    if (playerLevel == 1 && nb >= 1 && game->map[Y][X].linemate >= 1) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 2 && nb >= 2 && game->map[Y][X].linemate >= 1 && game->map[Y][X].deraumere >= 1 && game->map[Y][X].sibur >= 1) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 3 && nb >= 2 && game->map[Y][X].linemate >= 2 && game->map[Y][X].sibur >= 1 && game->map[Y][X].phiras >= 2) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 4 && nb >= 4 && game->map[Y][X].linemate >= 1 && game->map[Y][X].deraumere >= 1 && game->map[Y][X].sibur >= 2 && game->map[Y][X].phiras >= 1) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 5 && nb >= 4 && game->map[Y][X].linemate >= 1 && game->map[Y][X].deraumere >= 2 && game->map[Y][X].sibur >= 1 && game->map[Y][X].mendiane >= 3) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 6 && nb >= 6 && game->map[Y][X].linemate >= 1 && game->map[Y][X].deraumere >= 2 && game->map[Y][X].sibur >= 3 && game->map[Y][X].phiras >= 1 && game->map[Y][X].thystame >= 1) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else if (playerLevel == 7 && nb >= 6 && game->map[Y][X].linemate >= 2 && game->map[Y][X].deraumere >= 2 && game->map[Y][X].sibur >= 2 && game->map[Y][X].mendiane >= 2 && game->map[Y][X].phiras >= 2 && game->map[Y][X].thystame >= 2) {
        player->level++;
        sprintf(response, "Current level: %d\n", player->level);
        send(sockfd, response, strlen(response), 0);
    }
    else {
        send (sockfd, "ko\n", 3, 0);
    }
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ai_commands_2
*/

#include "../inc/server.h"

void handle_forward_function(int sockfd, game_t *game, int id)
{
    move_forward(sockfd, game, id);
}

void handle_right_function(int sockfd, game_t *game, int id)
{
    turn_right(sockfd, game, id);
}

void handle_left_function(int sockfd, game_t *game, int id)
{
    turn_left(sockfd, game, id);
}

void handle_inventory_function(int sockfd, game_t *game, int id)
{
    char response[1024];
    Player *player = get_player_by_id(game, id);
    sprintf(response, "[ food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d ]\n",
    player->inventory.food,
    player->inventory.linemate,
    player->inventory.deraumere,
    player->inventory.sibur,
    player->inventory.mendiane,
    player->inventory.phiras,
    player->inventory.thystame);
    send(sockfd, response, strlen(response), 0);
}

void handle_takeObject_function(int sockfd, game_t *game, int id, char *object)
{
    char response[1024];
    Player *player = get_player_by_id(game, id);
    if (strcmp(object, "food") == 0) {
        if (game->map[player->pos.y][player->pos.x].food > 0) {
            game->map[player->pos.y][player->pos.x].food--;
            player->inventory.food++;
            // add time
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "linemate") == 0) {
        if (game->map[player->pos.y][player->pos.x].linemate > 0) {
            game->map[player->pos.y][player->pos.x].linemate--;
            player->inventory.linemate++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "deraumere") == 0) {
        if (game->map[player->pos.y][player->pos.x].deraumere > 0) {
            game->map[player->pos.y][player->pos.x].deraumere--;
            player->inventory.deraumere++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "sibur") == 0) {
        if (game->map[player->pos.y][player->pos.x].sibur > 0) {
            game->map[player->pos.y][player->pos.x].sibur--;
            player->inventory.sibur++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "mendiane") == 0) {
        if (game->map[player->pos.y][player->pos.x].mendiane > 0) {
            game->map[player->pos.y][player->pos.x].mendiane--;
            player->inventory.mendiane++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "phiras") == 0) {
        if (game->map[player->pos.y][player->pos.x].phiras > 0) {
            game->map[player->pos.y][player->pos.x].phiras--;
            player->inventory.phiras++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "thystame") == 0) {
        if (game->map[player->pos.y][player->pos.x].thystame > 0) {
            game->map[player->pos.y][player->pos.x].thystame--;
            player->inventory.thystame++;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    }
    
    send(sockfd, response, strlen(response), 0);
}

void handle_setObject_function(int sockfd, game_t *game, int id, char *object)
{
    char response[1024];
    Player *player = get_player_by_id(game, id);
    if (strcmp(object, "food") == 0) {
        if (player->inventory.food > 0) {
            game->map[player->pos.y][player->pos.x].food++;
            player->inventory.food--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "linemate") == 0) {
        if (player->inventory.linemate > 0) {
            game->map[player->pos.y][player->pos.x].linemate++;
            player->inventory.linemate--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "deraumere") == 0) {
        if (player->inventory.deraumere > 0) {
            game->map[player->pos.y][player->pos.x].deraumere++;
            player->inventory.deraumere--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "sibur") == 0) {
        if (player->inventory.sibur > 0) {
            game->map[player->pos.y][player->pos.x].sibur++;
            player->inventory.sibur--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "mendiane") == 0) {
        if (player->inventory.mendiane > 0) {
            game->map[player->pos.y][player->pos.x].mendiane++;
            player->inventory.mendiane--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "phiras") == 0) {
        if (player->inventory.phiras > 0) {
            game->map[player->pos.y][player->pos.x].phiras++;
            player->inventory.phiras--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    } else if (strcmp(object, "thystame") == 0) {
        if (player->inventory.thystame > 0) {
            game->map[player->pos.y][player->pos.x].thystame++;
            player->inventory.thystame--;
            sprintf(response, "ok\n");
        } else {
            sprintf(response, "ko\n");
        }
    }
    send(sockfd, response, strlen(response), 0);
}
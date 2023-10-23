/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_player_level(int sockfd, game_t *game, int id)
{
    char buf[MAX_MSG_LEN];
    Player *player = get_player_by_id(game, id);
    snprintf(buf, MAX_MSG_LEN, "plv %d %d\n", player->id, player->level);
    write(sockfd, buf, strlen(buf));
}

void send_player_inventory(int sockfd, game_t *game, int id)
{
    char buf[MAX_MSG_LEN];
    Player *player = get_player_by_id(game, id);
    snprintf(buf, MAX_MSG_LEN, "pin %d %d %d %d %d %d %d %d %d %d\n", player->id,
    player->pos.x, player->pos.y, player->inventory.food,
    player->inventory.linemate, player->inventory.deraumere,
    player->inventory.sibur, player->inventory.mendiane,
    player->inventory.phiras, player->inventory.thystame);
    printf("buf = %s\n", buf);
    write(sockfd, buf, strlen(buf));
}

void send_unit_request(int sockfd, server_t *serv)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "sgt %d\n", serv->freq);
    write(sockfd, buf, strlen(buf));
}

void send_unit_modification(int sockfd, int new_unit)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "sst %d\n", new_unit);
    write(sockfd, buf, strlen(buf));
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_connection_new_player(int sockfd, Player *player)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pnw %d %d %d %d %d %s\n",
    player->id, player->pos.x, player->pos.y,
    player->orientation, player->level, player->team);
    printf("buf = %s\n", buf);
    write(sockfd, buf, strlen(buf));
}

void send_expulsion(int sockfd, Player *player)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pex %d\n", player->id);
    write(sockfd, buf, strlen(buf));
}

void send_broadcast(int sockfd, Player *player, const char *msg)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pbc %d %s\n", player->id, msg);
    write(sockfd, buf, strlen(buf));
}

void send_player_incantation_start(int sockfd, Player *player)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pic %d %d %d %d",
    player->pos.x, player->pos.y, player->level, player->id);
    write(sockfd, buf, strlen(buf));
}

void send_player_incantation_end(int sockfd, Player *player, int success)
{
    char buf[MAX_MSG_LEN];
    if (success == 0) {
        snprintf(buf, MAX_MSG_LEN, "pie %d %d success\n",
        player->pos.x, player->pos.y);
    } else {
        snprintf(buf, MAX_MSG_LEN, "pie %d %d failure\n",
        player->pos.x, player->pos.y);
    }
    write(sockfd, buf, strlen(buf));
}

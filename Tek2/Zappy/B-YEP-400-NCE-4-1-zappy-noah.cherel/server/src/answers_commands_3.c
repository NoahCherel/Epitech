/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_egg_laying_player(int sockfd, Player *player)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pfk %d\n", player->id);
    write(sockfd, buf, strlen(buf));
}

void send_player_death(int sockfd, Player *player)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "pdi %d\n", player->id);
    write(sockfd, buf, strlen(buf));
}

void send_end_game(int sockfd, char *winning_team)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "seg %s\n", winning_team);
    write(sockfd, buf, strlen(buf));
}

void send_unknown_command(int sockfd)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "suc\n");
    write(sockfd, buf, strlen(buf));
}

void send_command_parameter(int sockfd)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "sbp\n");
    write(sockfd, buf, strlen(buf));
}

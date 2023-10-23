/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_welcome(int sockfd)
{
    write(sockfd, "WELCOME\n", 8);
}

void handle_sgt(int sockfd, game_t *game)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "sgt %d\n", game->freq);
    write(sockfd, buf, strlen(buf));
}

void handle_msz(int sockfd, game_t *game)
{
    send_map_size(sockfd, game);
}

void handle_bct(int sockfd, game_t *game)
{
    send_tile_content(sockfd, game, 0, 0);
}

void handle_graphic(int sockfd, game_t *game)
{
    handle_msz(sockfd, game);
    handle_sgt(sockfd, game);
    handle_mct(sockfd, game);
    handle_tna(sockfd, game);
    game->graphicSockfd = sockfd;
}

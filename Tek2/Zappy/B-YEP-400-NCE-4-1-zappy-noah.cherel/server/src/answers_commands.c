/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_map_content(int sockfd, game_t *game)
{
    char buf[MAX_MSG_LEN];
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            snprintf(buf, MAX_MSG_LEN, "bct %d %d %d %d %d %d %d %d %d\n",
            game->width, game->height, game->map[y][x].food,
            game->map[y][x].linemate, game->map[y][x].deraumere,
            game->map[y][x].sibur, game->map[y][x].mendiane,
            game->map[y][x].phiras, game->map[y][x].thystame);
            write(sockfd, buf, strlen(buf));
            map_content_coding(sockfd, game, x);
        }
        write(sockfd, "\n", 1);
    }
}

void send_player_pos_all(int sockfd, game_t *game)
{
    for (int i = 0; i < game->num_players; i++)
        send_player_pos(sockfd, game, i);
}

void send_message(int sockfd, char *msg)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "msg %s\n", msg);
    write(sockfd, buf, strlen(buf));
}

void send_error(int sockfd, const char *msg)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "error\n%s\n", msg);
    write(sockfd, buf, strlen(buf));
}

void send_ok(int sockfd)
{
    write(sockfd, "ok\n", 3);
}

void send_ko(int sockfd)
{
    write(sockfd, "ko\n", 3);
}

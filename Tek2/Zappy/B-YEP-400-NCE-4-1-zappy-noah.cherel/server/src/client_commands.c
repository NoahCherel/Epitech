/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

void send_map_size(int sockfd, game_t *game)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "msz %d %d\n", game->width, game->height);
    write(sockfd, buf, strlen(buf));
}

void send_tile_content(int sockfd, game_t *game, int x, int y)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        game->map[y][x].food, game->map[y][x].linemate,
        game->map[y][x].deraumere, game->map[y][x].sibur,
        game->map[y][x].mendiane, game->map[y][x].phiras,
        game->map[y][x].thystame);
    write(sockfd, buf, strlen(buf));
}

void send_tile_content_all(int sockfd, game_t *game)
{
    for (int y = 0; y < game->height; y++)
        for (int x = 0; x < game->width; x++)
            send_tile_content(sockfd, game, x, y);
}

void send_team_names(int sockfd, game_t *game)
{
    char *buf = malloc(MAX_MSG_LEN);
    char *ptr = buf;
    for (int i = 0; game->teamNames[i] != NULL; i++) {
        ptr += snprintf(buf, MAX_MSG_LEN, "tna %s\n", game->teamNames[i]);
        write(sockfd, buf, strlen(buf));
    }
    free(buf);
}

void print_all_players(game_t *game)
{
    for (int i = 0; i < game->teamsNb; i++) {
        printf("Team: %s\n", game->teams[i].name);
        for (int j = 0; j < game->num_players; j++) {
            Player player = game->teams[i].players[j];
            printf("Player ID: %d\n", player.id);
            printf("Position: (%d, %d)\n", player.pos.x, player.pos.y);
            printf("Level: %d\n", player.level);
            printf("Orientation: %d\n", player.orientation);
            printf("Socket FD: %d\n", player.sockfd);
            printf("Team Name: %s\n", player.team);
            printf("Address: %s\n", inet_ntoa(player.addr.sin_addr));
            printf("Port: %d\n", ntohs(player.addr.sin_port));
            printf("Time Left: %d\n", player.timeleft);
            printf("Is Dead: %s\n", player.isdead ? "Yes" : "No");
            printf("\n");
        }
    }
}

int* find_team_by_player_id(game_t *game, int playerId)
{
    for (int i = 0; i < game->teamsNb; i++) {
        for (int j = 0; j < game->num_players; j++) {
            if (game->teams[i].players[j].id == playerId) {
                return (int[2]) {
                    i,
                    j
                };
            }
        }
    }
    return NULL;
}

void send_player_pos(int sockfd, game_t *game, int id)
{
    char buf[MAX_MSG_LEN];
    int *teamId = find_team_by_player_id(game, id);

    int i = teamId[0];
    int j = teamId[1];

    if (teamId != NULL) {
        snprintf(buf, MAX_MSG_LEN, "ppo %d %d %d %d\n", id,
        game->teams[i].players[j].pos.x, game->teams[i].players[j].pos.y,
        game->teams[i].players[j].orientation);
        printf("buf: %s", buf);
        write(sockfd, buf, strlen(buf));
    } else {
        printf("Error: Player with id %d not found\n", id);
    }
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answers_commands_7
*/

#include "../inc/server.h"

void map_content_coding(int sockfd, game_t *game, int x)
{
    if (x < game->width - 1)
        write(sockfd, " ", 1);
}

int add_player_to_team(game_t *game, char *team_name, int sockfd)
{
    for (int i = 0; i < game->teamsNb; i++) {
        printf("team name: %s\n", game->teams[i].name);
        if (strcmp(game->teams[i].name, team_name) == 0) {
            for (int j = 0; j < game->num_players; j++) {
                if (game->teams[i].players[j].sockfd == -1) {
                    game->teams[i].players[j].sockfd = sockfd;
                    game->teams[i].players[j].connected = true;
                    return game->teams[i].players[j].id;
                }
            }
            printf("Error: No available players in team '%s'\n", team_name);
            return -1;
        }
    }
    printf("Error: Team '%s' not found\n", team_name);
    return -1;
}

void send_map_size_player(int sockfd, game_t *game)
{
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "%d %d\n", game->width, game->height);
    write(sockfd, buf, strlen(buf));
}

void team_players_left_slot(int sockfd, game_t *game, char *team_name)
{
    team_t *team = NULL;
    for (int i = 0; i < game->teamsNb; i++) {
        if (strcmp(game->teams[i].name, team_name) == 0) {
            team = &game->teams[i];
            break;
        }
    }
    if (team == NULL) {
        printf("Error: team '%s' not found\n", team_name);
        return;
    }
    int places_left = game->num_players - team->nb_players;
    char buf[MAX_MSG_LEN];
    snprintf(buf, MAX_MSG_LEN, "%d\n", places_left);
    write(sockfd, buf, strlen(buf));
}

void handle_mct(int sockfd, game_t *game)
{
    send_tile_content_all(sockfd, game);
}

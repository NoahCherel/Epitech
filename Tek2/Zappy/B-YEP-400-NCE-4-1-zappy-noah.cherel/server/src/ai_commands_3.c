/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ai_commands_3
*/

#include "../inc/server.h"

static const int off[5] = {0, 4, 2, 0, 6};

void handle_fork_function(int sockfd, game_t *game, int id)
{
    game->num_players++;
    printf("id = %d\n", id);
    send(sockfd, "ok\n", 3, 0);
}

void send_message_to_all_players(game_t *game, char *message)
{
    char response[1024];
    sprintf(response, "message %s\n", message);
    for (int i = 0; i < game->num_players; i++) {
        send(game->players[i].sockfd, response, strlen(response), 0);
    }
}

int find_direction(Player *r, Player *s)
{
    if (s->pos.x == r->pos.x) return s->pos.y < r->pos.y ? 5 : 1;
    if (s->pos.y == r->pos.y) return s->pos.x < r->pos.x ? 3 : 7;
    if (s->pos.x < r->pos.x && s->pos.y > r->pos.y) return 2;
    if (s->pos.x < r->pos.x && s->pos.y > r->pos.y) return 4;
    if (s->pos.x > r->pos.x && s->pos.y < r->pos.y) return 6;
    if (s->pos.x > r->pos.x && s->pos.y > r->pos.y) return 8;
    return 0;
}

int broadcast_finder(Player *player, Player *broadcaster)
{
    int res;
    if (player->pos.x == broadcaster->pos.x && player->pos.y == broadcaster->pos.y)
        return 0;
    res = find_direction(player, broadcaster) + off[player->orientation];
    return res % 8 != 0 ? res % 8 : 8;
}

void handle_broadcast_message(int sockfd, char *message, game_t *game)
{
    char tile_str[10];
    int player_id = find_player_by_sockfd(game, sockfd);
    Player *player = get_player_by_id(game, player_id);
    sscanf(message, "Broadcast %s", tile_str);
    int x = player->pos.x; int y = player->pos.y;
    char message_str[100];
    for (int i = 0; i < game->teamsNb; i++) {
        printf("Team: %s\n", game->teams[i].name);
        for (int j = 0; j < game->num_players; j++) {
            if (game->teams[i].players[j].connected == true && game->teams[i].players[j].level == player->level && game->teams[i].players[j].id != player->id && game->teams[i].players[j].team == player->team) {
                printf("player doing broadcast: %d, %d\n", x, y);
                printf("player pos: %d, %d\n", game->teams[i].players[j].pos.x, game->teams[i].players[j].pos.y);
                int dir = broadcast_finder(&game->teams[i].players[j], player);
                printf("dir: %d\n", dir);
                snprintf(message_str, 100, "message %d, %s\n", dir, message);
                send(game->teams[i].players[j].sockfd, message_str, strlen(message_str), 0);
            }
            if (x == game->teams[i].players[j].pos.x && y == game->teams[i].players[j].pos.y && game->teams[i].players[j].connected == true && game->teams[i].players[j].level == player->level && game->teams[i].players[j].id != player->id && game->teams[i].players[j].team == player->team) {
                send (sockfd, "ok\n", 3, 0);
            }
        }
    }
    send_broadcast(game->graphicSockfd, player, message);
}

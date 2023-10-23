/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** setup_game
*/

#include "../inc/server.h"

#include <math.h>

void init_map(game_t *game)
{
    game->map = malloc(sizeof(cell_t *) * game->height);
    for (int i = 0; i < game->height; i++) {
        game->map[i] = malloc(sizeof(cell_t) * game->width);
        for (int j = 0; j < game->width; j++) {
            game->map[i][j].food = 0;
            game->map[i][j].linemate = 0;
            game->map[i][j].deraumere = 0;
            game->map[i][j].sibur = 0;
            game->map[i][j].mendiane = 0;
            game->map[i][j].phiras = 0;
            game->map[i][j].thystame = 0;
            game->map[i][j].players = 0;
        }
    }
    place_materials(game);
}

void init_players(game_t *game)
{
    game->teams = malloc(sizeof(team_t) * game->teamsNb);
    srand(time(NULL)); int playerIndex = 0;
    for (int j = 0; j < game->teamsNb; j++) {
        game->teams[j].players = malloc(sizeof(Player) * game->num_players);
        game->teams[j].name = strdup(game->teamNames[j]);
        for (int i = 0; i < game->num_players; i++) {
            game->teams[j].players[i].id = playerIndex; playerIndex++;
            game->teams[j].players[i].pos.x = rand() % game->width;
            game->teams[j].players[i].pos.y = rand() % game->height;
            game->teams[j].players[i].level = 1;
            game->teams[j].players[i].orientation = rand() % 4;
            game->teams[j].players[i].sockfd = -1;
            game->teams[j].players[i].team = strdup(game->teams[j].name);
            game->teams[j].players[i].addr.sin_family = AF_INET;
            game->teams[j].players[i].addr.sin_addr.s_addr = INADDR_ANY;
            game->teams[j].players[i].addr.sin_port = 0;
            game->teams[j].players[i].timeleft = 1260 / game->freq;
            game->teams[j].players[i].isdead = false;
            game->teams[j].players[i].connected = false;
            game->teams[j].players[i].inventory.food = 10;
            game->teams[j].players[i].inventory.linemate = 0;
            game->teams[j].players[i].inventory.deraumere = 0;
            game->teams[j].players[i].inventory.sibur = 0;
            game->teams[j].players[i].inventory.mendiane = 0;
            game->teams[j].players[i].inventory.phiras = 0;
            game->teams[j].players[i].inventory.thystame = 0;
            game->teams[j].nb_players++;
            game->map[game->teams[j].players[i].pos.y][game->teams[j].players[i].pos.x].players++;
        }
    }
}

void init_teams(game_t *game)
{
    game->teams = malloc(sizeof(team_t) * game->teamsNb);
    for (int i = 0; i < game->teamsNb; i++) {
        game->teams[i].name = strdup(game->teamNames[i]);
        game->teams[i].players = NULL;
        game->teams[i].is_full = false;
    }
}

void display_map(int fd, game_t *game)
{
    size_t max_data_size = game->height * game->width * 100;
    char* map_data = malloc(max_data_size);
    if (map_data == NULL) {
        fprintf(stderr, "Failed to allocate memory for map data.\n"); return;
    }
    size_t offset = 0;
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            int written = snprintf(map_data + offset, max_data_size - offset,
            "%d %d %d %d %d %d %d %d %d %d\n", x, y,
                game->map[y][x].food, game->map[y][x].linemate,
                game->map[y][x].deraumere, game->map[y][x].sibur,
                game->map[y][x].mendiane, game->map[y][x].phiras,
                game->map[y][x].thystame, game->map[y][x].players);
            if (written < 0) {
                fprintf(stderr, "Failed to format map data.\n");
                free(map_data); return;
            }
            offset += written;
        }
    }
    write(fd, map_data, offset); free(map_data);
}

game_t *init_game(server_t *server)
{
    game_t *game = malloc(sizeof(game_t));
    game->width = server->width;
    game->height = server->height;
    game->num_players = server->clientsNb;
    game->freq = server->freq;
    game->time = 0;
    game->teamNames = server->teamNames;
    game->teamsNb = server->teamsNb;
    game->handler = 0;
    game->graphicSockfd = -1;
    game->materials_timer = get_current_time() + 20;
    game->players_timer = get_current_time() + 1260 / game->freq;
    init_map(game);
    init_teams(game);
    init_players(game);
    return game;
}

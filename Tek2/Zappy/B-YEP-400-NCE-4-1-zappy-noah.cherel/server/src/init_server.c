/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** initServer
*/

#include "../inc/server.h"

int get_teams_nb(server_t *server)
{
    int i = 0;
    while (server->teamNames[i] != NULL) {
        i++;
    }
    return i;
}

server_t *create_server(int* size, char** t, int c)
{
    server_t *server = malloc(sizeof(server_t));
    server->port = size[0];
    server->width = size[1];
    server->height = size[2];
    server->teamNames = t;
    server->clientsNb = c;
    server->teamsNb = get_teams_nb(server);
    server->freq = size[3];
    return server;
}

void rem_serv(server_t *server)
{
    free(server->teamNames);
    free(server);
}

void parse_tags(char** t, char** tags, int tagIndex)
{
    int i = 0;
    while (i < tagIndex && tags[i][0] != '-') {
        t[i] = tags[i];
        i++;
    }
    t[i] = NULL;
}

server_t *parsing_args(int ac, char** av)
{
    int p = 0, w = 0, h = 0, c = 0, f = 100;
    char** t = malloc(sizeof(char*) * (ac - 6));
    for (int i = 1; i < ac; i++) {
        switch (av[i][1]) {
            case 'p': p = atoi(av[i + 1]); break;
            case 'x': w = atoi(av[i + 1]); break;
            case 'y': h = atoi(av[i + 1]); break;
            case 'n':
                parse_tags(t, &av[i + 1], ac - i - 1);
                break;
            case 'c': c = atoi(av[i + 1]); break;
            case 'f': f = atoi(av[i + 1]); break;
            default: break;
        }
    }
    if (p == 0 || w == 0 || h == 0 || t == NULL || c == 0 || f == 0) exit(84);
    int *size = malloc(sizeof(int) * 4); size[0] = p; size[1] = w; size[2] = h;
    size[3] = f; server_t *server = create_server(size, t, c); return server;
}

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ftp_server
*/

#include "../include/ftp_server.h"

int status_server(server_t *server)
{
    if (server->socket == -1) {
        printf("socket creation failed...\n"); exit(0);
    } else
        printf("Socket successfully created..\n");
    if ((bind(server->socket, (SA*)&server->servaddr,
    sizeof(server->servaddr))) != 0) {
        printf("socket bind failed...\n"); exit(0);
    } else
        printf("Socket successfully binded..\n");
    if ((listen(server->socket, 5)) != 0) {
        printf("Listen failed...\n"); exit(0);
    } else
        printf("Server listening..\n");
    return 0;
}

server_t *init_server(int port, char *path)
{
    server_t *server = malloc(sizeof(server_t));
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    server->servaddr.sin_family = AF_INET;
    server->servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->servaddr.sin_port = htons(port);
    server->path = path;
    status_server(server);
    return server;
}

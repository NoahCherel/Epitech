/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ftp_client
*/

#include "../include/ftp_server.h"

client_t *create_client(server_t *serv, char *ip)
{
    client_t *client = malloc(sizeof(client_t));
    client->fd = serv->fd_client;
    client->ip = ip;
    client->logged = 0;
    client->username = NULL;
    client->password = NULL;
    client->mode = 0;
    return client;
}

int is_valid_command(char *command)
{
    char *commands[15] = {"QUIT", "PWD", "TYPE", "USER", "PASS", "CWD",
                                "LIST", "RETR", "STOR", "DELE", "PASV", "PORT",
                                "NOOP", "HELP", "CDUP"};
    for (int i = 0; i < 15; i++) {
        if (strncmp(commands[i], command, strlen(commands[i])) == 0) {
            return 1;
        }
    }
    return 0;
}

int new_client(server_t *server, struct sockaddr_in client)
{
    char *ip = inet_ntoa(client.sin_addr);
    char buffer[MAX];
    client_t *c = malloc(sizeof(client_t));
    c = create_client(server, ip);
    write(c->fd, "220 Welcome to the FTP server\r\n",
    strlen("220 Welcome to the FTP server\r\n"));
    while (1) {
        bzero(buffer, MAX);
        read(c->fd, buffer, sizeof(buffer));
        if (!is_valid_command(buffer)) {
            write(c->fd, "500 Unknown command.\r\n",
            strlen("500 Unknown command.\r\n"));
            continue;
        }
        handle_all_command(server, buffer, c);
    }
    return 0;
}

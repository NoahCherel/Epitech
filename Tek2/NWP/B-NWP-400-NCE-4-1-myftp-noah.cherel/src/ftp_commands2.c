/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-noah.cherel
** File description:
** ftp_commands2
*/

#include "../include/ftp_server.h"

void noop_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        write(client->fd, "200 NOOP ok.\r\n", strlen("200 NOOP ok.\r\n"));
    }
}

void help_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        write(client->fd, "214 Help OK.\r\n", strlen("214 Help OK.\r\n"));
    }
}

void user_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (strcmp(buffer, "Anonymous") == 0) {
        write(client->fd, "331 User name okay, need password.\r\n",
        strlen("331 User name okay, need password.\r\n"));
        client->logged = 1;
        return;
    }
    if (buffer[0] != ' ') {
        write(client->fd, "331 User name okay, need password.\r\n",
        strlen("331 User name okay, need password.\r\n"));
        client->logged = 0;
        return;
    }
    write(client->fd, "530 Login incorrect.\r\n",
    strlen("530 Login incorrect.\r\n"));
    client->logged = 0;
}

void pass_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        if (client->logged == 1 && strcmp(buffer, " ") == 0) {
            write(client->fd, "230 User logged in, proceed.\r\n",
            strlen("230 User logged in, proceed.\r\n"));
            client->logged = 2;
        } else {
            write(client->fd, "530 Login incorrect.\r\n",
            strlen("530 Login incorrect.\r\n"));
            client->logged = 0;
        }
    }
}

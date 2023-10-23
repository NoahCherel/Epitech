/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ftp_commands
*/

#include "../include/ftp_server.h"

void quit_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    write(client->fd, "221 Goodbye.\r\n", strlen("221 Goodbye.\r\n"));
    exit(0);
}

void pwd_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    char *path = getcwd(NULL, 0);
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        write(client->fd, "257 \"", strlen("257 \""));
        write(client->fd, path, strlen(path));
        write(client->fd, "\"\r\n", strlen("\"\r\n"));
    }
}

void cwd_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        if (chdir(buffer) == 0) {
            write(client->fd, "250 Requested file action okay, completed.\r\n",
            strlen("250 Requested file action okay, completed.\r\n"));
        } else {
            write(client->fd, "550 Requested action not taken.\r\n",
            strlen("550 Requested action not taken.\r\n"));
        }
    }
}

void cdup_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        if (chdir("..") == 0) {
            write(client->fd, "200 CDUP okay.\r\n",
            strlen("200 CDUP okay.\r\n"));
        } else {
            write(client->fd, "550 Requested action not taken.\r\n",
            strlen("550 Requested action not taken.\r\n"));
        }
    }
}

void dele_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n"));
        return;
    } else {
        if (remove(buffer) == 0) {
            write(client->fd, "250 Requested file action okay, completed.\r\n",
            strlen("250 Requested file action okay, completed.\r\n"));
        } else {
            write(client->fd, "550 Requested action not taken.\r\n",
            strlen("550 Requested action not taken.\r\n"));
        }
    }
}

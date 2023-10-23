/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** misc
*/

#include "../include/server.h"

int setup_fd_set(int sockfd, Client *cli[], fd_set *readfds)
{
    FD_ZERO(readfds);
    FD_SET(sockfd, readfds);
    int max_fd = sockfd;

    for (int i = 0; i < M_CLI; i++) {
        if (cli[i] != NULL && cli[i]->sockfd > max_fd) {
            max_fd = cli[i]->sockfd;
        }
    }

    for (int i = 0; i < M_CLI; i++) {
        if (cli[i] != NULL) {
            FD_SET(cli[i]->sockfd, readfds);
        }
    }

    return max_fd;
}

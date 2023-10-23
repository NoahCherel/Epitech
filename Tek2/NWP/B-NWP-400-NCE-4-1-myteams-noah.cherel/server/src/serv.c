/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myteams-noah.cherel
** File description:
** serv
*/

#include "../include/server.h"
#include "../../shared.h"

int send_data(struct Client *client)
{
    char message[1024];
    snprintf(message, sizeof(message), "User:%s UUID:%s",
    client->user_name, client->uuid);
    send(client->sockfd, message, strlen(message), 0);
    return 0;
}

int accept_new_client(int sockfd, Client *clients[], int index)
{
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
    if (client_sockfd == -1) {
        perror("Accept failed");
        exit(84);
    }
    return client_sockfd;
}

void load_clients_data(Client *clients[], int *index)
{
    FILE *fp = fopen(SAVE_FILE_PATH, "rb"); char l[BUF_SIZE];
    if (fp == NULL) {
        printf("Failed to open save file.\n"); return;
    }
    while (fgets(l, BUF_SIZE, fp) != NULL) {
        if (strstr(l, "User:") != NULL && strstr(l, "UUID:") != NULL
        && strstr(l, "STATUS:") != NULL) {
            char *u_s = strstr(l, "User:") + 5, *u_d = strstr(l, "UUID:") - 2;
            char *uu_s = strstr(l, "UUID:") + 5;
            char *uu_d = strstr(l, "STATUS:") - 2;
            char *s_s = strstr(l, "STATUS:") + 8, *s_e = strstr(l, "\n") - 2;
            char *nam = strndup(u_s, u_d - u_s + 1);
            char *uuid = strndup(uu_s, uu_d - uu_s + 1);
            int status = atoi(strndup(s_s, s_e - s_s + 1));
            clients[*index] = malloc(sizeof(Client));
            clients[*index]->status = status; clients[*index]->user_name = nam;
            clients[*index]->uuid = uuid; (*index)++; USR_LOAD(uuid, nam);
        }
    }
    fclose(fp);
}

void signal_handler(int sig)
{
    exit_flag = 1;
}

int loop_server(int sockfd, Client *cli[], int index)
{
    load_clients_data(cli, &index); fd_set readfds;
    int activity, client_sockfd; signal(SIGINT, signal_handler);
    while (!exit_flag) {
        int max_fd = setup_fd_set(sockfd, cli, &readfds);
        activity = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        if (activity < 0 && errno == EINTR) {
            continue; perror("Select failed"); exit(84);
        }
        if (FD_ISSET(sockfd, &readfds)) {
            client_sockfd = accept_new_client(sockfd, cli, index);
            index = add_client(cli, client_sockfd, index);
        }
        index = handle_client_data(cli, index, &readfds);
    }
    for (int i = 0; i < M_CLI; i++) if (cli[i] != NULL) close(cli[i]->sockfd);
    close(sockfd); return 0;
}

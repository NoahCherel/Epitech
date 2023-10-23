/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** setup_server
*/

#include "../inc/server.h"
#define NEW_CO_STR "[+] New connection from %s:%d\n"

int create_socket(server_t* server)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(server->port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return -1;
    }
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(sockfd);
        return -1;
    }
    return sockfd;
}

int accept_connection(int sockfd)
{
    struct sockaddr_in c_addr = {0};
    socklen_t c_len = sizeof(c_addr);
    int c_sockfd = accept(sockfd, (struct sockaddr*)&c_addr, &c_len);
    if (c_sockfd == -1) {
        perror("accept");
    }
    return c_sockfd;
}

void handle_new_connection(int sockfd, int* clients)
{
    int c_sockfd = accept_connection(sockfd);
    switch (c_sockfd) {
        case -1:
            break;
        default:
            struct sockaddr_in c_addr; socklen_t c_len = sizeof(c_addr);
            getpeername(c_sockfd, (struct sockaddr*)&c_addr, &c_len);
            printf(NEW_CO_STR, inet_ntoa(c_addr.sin_addr),
            ntohs(c_addr.sin_port));
            int i;
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = c_sockfd; send_welcome(c_sockfd); break;
                }
            }
            if (i == MAX_CLIENTS) {
                fprintf(stderr, "Too many clients. Connection rejected.\n");
                close(c_sockfd);
            } break;
    }
}

void h_client_requests(int* clients, fd_set* readfds, server_t* serv)
{
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    command_queue_t queue; initialize_queue(&queue);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        int clifd = clients[i];
        if (clifd > 0 && FD_ISSET(clifd, readfds)) {
            char buf[MAX_MSG_LEN];
            ssize_t n = read(clifd, buf, MAX_MSG_LEN);
            if (n > 0) {
                buf[n] = '\0';
                getpeername(clifd, (struct sockaddr*)&cli_addr, &cli_len);
                printf("[received] [%s:%d] %s\n", inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port), buf);
                handle_all_commands(clifd, serv->game, buf, &queue);
            } else if (n == 0) {
                printf("Client disconnected\n");
                close(clifd);
                clients[i] = 0;
            } else {
                perror("read");
            }
        }
    }
}

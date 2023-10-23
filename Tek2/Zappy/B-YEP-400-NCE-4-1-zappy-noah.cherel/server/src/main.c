/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "../inc/server.h"
#define SET ((FD_SET(clifd, &readf), (clifd > maxfd) ? clifd : maxfd)) : maxfd;
#include <fcntl.h>
#include <errno.h>
#include <sys/uio.h>

long get_current_time(void)
{
    struct timeval tv;
    long current_time;

    gettimeofday(&tv, NULL);
    current_time = tv.tv_sec * (uint64_t)1000000 + tv.tv_usec;
    return current_time / 1000000;
}

ssize_t recv_nonblock(int sockfd, char *buf, size_t len) {
    ssize_t n = recv(sockfd, buf, len, MSG_DONTWAIT);
    if (n == -1 && errno == EAGAIN) {
        return 0;
    }
    return n;
}

int setNonBlocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }

    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return -1;
    }

    return 0;
}

void start_server(server_t *server) {
    int sockfd = create_socket(server);
    if (sockfd == -1) {
        rem_serv(server);
        exit(84);
    }

    if (setNonBlocking(sockfd) == -1) {
        rem_serv(server);
        exit(84);
    }

    game_t *game = init_game(server);
    server->game = game;
    command_queue_t queue;
    initialize_queue(&queue);
    game->queue = &queue;

    if (!game) {
        rem_serv(server);
        exit(84);
    }

    printf("\n");
    int maxfd = sockfd;
    fd_set readfds;
    int clients[MAX_CLIENTS] = {0};

    printf("[+] Zappy server is listening on 0.0.0.0:%d\n", server->port);

    int timeout = 0;
    struct timeval tv;

    struct sockaddr_in cli_addr;
    socklen_t addrlen = sizeof(cli_addr);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int clifd = clients[i];
            if (clifd > 0) {
                FD_SET(clifd, &readfds);
                maxfd = (clifd > maxfd) ? clifd : maxfd;
            }
        }

        tv.tv_sec = timeout;
        tv.tv_usec = 10000;

        int ready = select(maxfd + 1, &readfds, NULL, NULL, &tv);
        if (ready == -1) {
            perror("select");
            break;
        } else if (ready == 0) {
            update_resources(game);
            update_players(game);
            execute_ai_command(game->queue, game);
        } else {
            if (FD_ISSET(sockfd, &readfds)) {
                handle_new_connection(sockfd, clients);
            }

            for (int i = 0; i < MAX_CLIENTS; i++) {
                int clifd = clients[i];
                if (clifd > 0 && FD_ISSET(clifd, &readfds)) {
                    char buf[MAX_MSG_LEN];
                    struct iovec iov[1];
                    iov[0].iov_base = buf;
                    iov[0].iov_len = MAX_MSG_LEN;

                    struct msghdr msg;
                    memset(&msg, 0, sizeof(msg));
                    msg.msg_iov = iov;
                    msg.msg_iovlen = 1;

                    ssize_t n = recvmsg(clifd, &msg, 0);
                    if (n > 0) {
                        buf[n] = '\0';
                        getpeername(clifd, (struct sockaddr*)&cli_addr, &addrlen);
                        //printf("[received] [%s:%d] %s\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buf);
                        handle_all_commands(clifd, game, buf, game->queue);
                        //send_tile_content_all(game->graphicSockfd, game);
                    } else if (n == 0) {
                        printf("Client disconnected\n");
                        close(clifd);
                        clients[i] = 0;
                    } else if (n == -1) {
                        if (errno != EAGAIN) {
                            perror("recv");
                        }
                    }
                }
            }
        }
    }
    close(sockfd);
    rem_serv(server);
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        help();
        return 0;
    }
    server_t *server = parsing_args(argc, argv);
    if (!server) {
        return 84;
    }

    start_server(server);
    free(server);
    return 0;
}
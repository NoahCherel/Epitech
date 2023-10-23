/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/server.h"

int create_server_socket(int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(84);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)
        &server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(84);
    }
    return sockfd;
}

int add_client(Client *clients[], int client_sockfd, int index)
{
    clients[index] = malloc(sizeof(Client));
    clients[index]->sockfd = client_sockfd;
    return index + 1;
}

void remove_client(Client *clients[], int index)
{
    close(clients[index]->sockfd);
    free(clients[index]);
    clients[index] = NULL;
}

int run_server(int sockfd)
{
    Client *clients[M_CLI];
    for (int i = 0; i < M_CLI; i++)
        clients[i] = NULL;
    loop_server(sockfd, clients, 0);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./server port\n"); exit(84);
    }
    int port = atoi(argv[1]);
    if (port < 1 || port > 65534)  exit(84);
    int sockfd = create_server_socket(port);
    if (listen(sockfd, 5) == -1) {
        perror("Listen failed");
        exit(84);
    }
    return run_server(sockfd);
}

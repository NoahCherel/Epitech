/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** utils
*/

#include "../inc/server.h"

void help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
    printf("... -c clientsNb -f freq\n");
    printf("port is the port number\n");
    printf("width is the width of the world\n");
    printf("height is the height of the world\n");
    printf("nameX is the name of the team X\n");
    printf("clientsNb is the number of authorized clients per team\n");
    printf("freq is the reciprocal of time unit for execution of actions\n");
    exit(0);
}

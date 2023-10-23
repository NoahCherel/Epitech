/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** management
*/

#include "../include/ftp_server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("port is the port number on which the server socket listens.\n");
    printf("path is the path to the home directory for the Anonymous user.\n");
    exit(0);
}

/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** solver
*/

#include "../include/my.h"

char *txttoint(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    if (stat(filepath, &st) == -1) {
        close(fd);
    }
    char *buffer = malloc(st.st_size + sizeof(char));
    read(fd, buffer, st.st_size);
    close (fd);
    return (buffer);
}

int main (int ac, char **av)
{
    char *maze;
    maze = txttoint(av[1]);
    my_putstr(maze);
    return (0);
}

/*
** EPITECH PROJECT, 2021
** cat
** File description:
** day12
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int display(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        int fd = open(av[i], O_RDONLY);
        char buf[1];
        while (read(fd, buf, 1) != 0) {
            my_putstr(buf);
        }
        close(fd);
    }
    return (0);
}

int main(int ac, char **av)
{
    display(ac ,av);
}

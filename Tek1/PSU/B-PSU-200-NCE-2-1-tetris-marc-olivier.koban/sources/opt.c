/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** opt
*/

#include "../include/my.h"

int my_help(int ac, char **av)
{
    my_putstr_1("Usage: "); my_putstr_1(av[0]); my_putstr_1(" [options]\n");
    my_putstr_1("Options:\n"); my_putstr_1("  --help\t\tDisplay this help\n");
    my_putstr_1("  -L --level={num} \tStart Tetris at level num (def: 1)\n");
    my_putstr_1("  -l --key-left={K}\tMove the tetrimino LEFT using the K ");
    my_putstr_1("key (def: left arrow)\n");
    my_putstr_1("  -r --key-right={K}\tMove the tetrimino RIGHT ");
    my_putstr_1("using the K key (def: right arrow)\n");
    my_putstr_1("  -t --key-turn={K}\tTURN the tetrimino using the K ");
    my_putstr_1("key (def: top arrow)\n");
    my_putstr_1("  -d --key-drop={K}\tDROP the tetrimino using the K ");
    my_putstr_1("key (def: down arrow){K}\n");
    my_putstr_1("  -q --key-quit={K}\tQuit the game using the K ");
    my_putstr_1("key (def: 'q' key)\n");
    my_putstr_1("  -p --key-pause={K}\tPAUSE/RESTART the game using the K ");
    my_putstr_1("key (def: space bar)\n");
    my_putstr_1("  --map-size={row,col}\tSet the number of rows and ");
    my_putstr_1("columns of the map (def: 20,10)\n");
    my_putstr_1("  -w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr_1("  -D --debug\t\tDebug mode (def: false)\n");
    return (0);
}

int is_number(char *str)
{
    int i = 0;
    int cpt = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            cpt++;
        }
        i++;
    }
    if (cpt == my_strlen(str)) {
        return (1);
    }
    return (0);
}

int nb_level(char *buf)
{
    int i = 0;
    while (buf[i] != '\0') {
        if (buf[i] == '=' || buf[i] == ' ') {
            buf[i] = buf[i + 1];
            buf[i + 1] = '\0';
        }
        i++;
    }
    if (is_number(buf) == 0) {
        return (84);
    } else
        my_strtoint(buf);
}

char *get_next(char *buf)
{
    int i = 0, j = 0;
    char *next = malloc(sizeof(char) * my_strlen(buf));
    while (buf[i] != '\0') {
        if (buf[i] == ',') {
            i++;
            while (buf[i] != '\0') {
                next[j] = buf[i];
                i++;
                j++;
            }
            next[j] = '\0';
            return (next);
        }
        i++;
    }
    return (NULL);
}

char *get_size(char *buf)
{
    int i = 0;
    char *row = malloc(sizeof(char) * my_strlen(buf));
    while (buf[i] != '\0') {
        row[i] = buf[i];
        if (buf[i] == ',') {
            row[i] = '\0';
        }
        i++;
    }
    return (row);
}

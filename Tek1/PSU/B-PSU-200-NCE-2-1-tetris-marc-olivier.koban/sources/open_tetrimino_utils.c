/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** open_tetetrimino_utils
*/

#include "../include/my.h"

char *txttoint(char *filepath)
{
    char *str = NULL;
    str = "./tetriminos/";
    str = my_strcat(str, filepath);
    int fd = open(str, O_RDONLY);
    struct stat st;
    if (stat(str, &st) == -1) {
        close(fd);
    }
    char *buffer = malloc(st.st_size + sizeof(char));
    read(fd, buffer, st.st_size);
    close(fd);
    return (buffer);
}

char *remove_first_line(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\n') {
        i++;
    }
    i++;
    while (str[i] != '\0') {
        new_str[j] = str[i];
        i++;
        j++;
    }
    new_str[j] = '\0';
    return (new_str);
}

int check_tetrimino(char *filepath)
{
    int i = 0, m = 0;
    while (filepath[i] != '\0') {
        if (filepath[i] == '.') {
            (filepath[i + 1] == 't' && filepath[i + 2] == 'e' &&
            filepath[i + 3] == 't' && filepath[i + 4] == 'r' &&
            filepath[i + 5] == 'i' && filepath[i + 6] == 'm' &&
            filepath[i + 7] == 'i' && filepath[i + 8] == 'n' &&
            filepath[i + 9] == 'o') ? m = 1 : 0;
        }
        i++;
    }
    if (m == 1) {
        return (0);
    }
    return (84);
}

char *print_first_line(char *str)
{
    int i = 0;
    int j = 0;
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\n') {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

int check(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '*') {
            return (0);
        }
        i++;
    }
    return (84);
}

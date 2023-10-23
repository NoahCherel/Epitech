/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** my_lib3
*/

#include "../include/my.h"

int count_line(char *list)
{
    int count = 0;
    for (int x = 0; list[x] != '\0'; x++) {
        if (list[x] == '\n') {
            count++;
        }
    }
    count++;
    return (count);
}

int word_longer(char *filepath)
{
    int big = 0;
    int count = 0;
    for (int x = 0; filepath[x] != '\0'; x++) {
        if (filepath[x] == '\n') {
            count = 0;
        } else {
            count++;
        }
        if (count > big) big = count;
    }
    return (big);
}

char *txttochar(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    if (stat(filepath, &st) == -1) {
        close(fd);
        return ("Error");
    }
    char *buffer = malloc(st.st_size + sizeof(char));
    read(fd, buffer, st.st_size);
    close (fd);
    return (buffer);
}

char *my_revstr(char *str)
{
    int srclen = my_strlen(str);
    int i, temp;
    for (i = 0; i < srclen / 2; i++) {
        temp = str[i];
        str[i] = str[srclen - i - 1];
        str[srclen - i - 1] = temp;
    }
    return (str);
}

void my_putstr_1(char const *str)
{
    write(1,  str, my_strlen(str));
}

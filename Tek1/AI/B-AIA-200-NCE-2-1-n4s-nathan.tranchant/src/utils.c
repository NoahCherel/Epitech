/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

void my_putstr(char *str, int fd)
{
    write(fd, str, my_strlen(str));
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

float my_strtof(char *str)
{
    float nb = 0.0;
    int i = 0, idx = 0;
    while (str[idx] != 0 && str[idx] >= '0' && str[idx] <= '9') {
        nb = nb * 10.0 + (str[idx++] - 48);
    }
    idx++;
    if (str[idx] == '.') {
        while (str[idx] != 0) {
            nb = nb * 10.0 + (str[idx] - 48);
            i--;
        }
    }
    while (i++ < 0) nb *= 0.1;
    return (nb);
}

char *my_strndup(char *str, int n)
{
    char *new_str = malloc(my_strlen(str) + 1);
    int i = 0;
    while (str[i] && i < n) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = 0;
    return (new_str);
}

char **str_to_word_array(char *str, char delim)
{
    int i = 0, j = 0, k = 0, new_word = 1;
    char **tab;
    while (str[i] != '\0') {
        if (str[i] != delim && new_word == 0)
            j++, new_word = 1;
        else if (str[i] == delim)
            new_word = 0;
        i++;
    }
    tab = malloc(sizeof(char *) * (j + 1));
    if (tab == NULL) return (NULL);
    i = 0, j = 0, k = 0, new_word = 1;
    while (str[i] != '\0') {
        while (str[i] != '\0' && str[i] != delim)
            i++, j++, new_word = 0;
        if (new_word == 0) tab[k] = my_strndup(str + i - j, j), k++, j = 0;
        while ((str[i] == delim) && str[i] && i++);
    } tab[k] = '\0';
    return (tab);
}

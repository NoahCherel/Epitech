/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** task03
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return(i);
}

char *my_revstr(char *str)
{
    int i;
    int a;
    int len = my_strlen(str);
    for(i = 0; i < len / 2; i++) {
        a = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = a;
    }
    return(str);
}

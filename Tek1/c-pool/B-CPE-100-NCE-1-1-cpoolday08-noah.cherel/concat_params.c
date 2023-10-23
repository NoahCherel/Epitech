/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** concat
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
    int i;
    int j;
    char *str;
    int strlen1 = 0;
    for (i = 0; i < argc; i++) {
        strlen1 = strlen1 + my_strlen(argv[i]) + 1;
    }
    str = malloc(strlen1);
    int pos = 0;
    for (i = 0; i < argc; i++) {
        for (j = 0; j < my_strlen(argv[i]); j++) {
            str[pos] = argv[i][j];
            pos++;
        }
        str[pos] = '\n';
        pos++;
    }
    str[pos] = '\0';
    return (str);
}

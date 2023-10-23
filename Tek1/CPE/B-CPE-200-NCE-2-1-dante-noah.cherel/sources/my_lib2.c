/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** my_lib2 my_defender
*/

#include "../include/my.h"

int my_chartoint(char str)
{
    int num = 0;
    num = num * 10 + (str - 48);
    return (num);
}

int my_strtoint(char *str)
{
    int num = 0;
    int i = 0;
    int j = my_strlen(str) - 1;
    int run = 1;
    while (run == 1) {
        num += (my_chartoint(str[j]) * my_compute_power_rec(10, i));
        i += 1;
        j -= 1;
        if (j < 0) {
            run = 0;
        }
    }
    return (num);
}

void array_to_2d(char **final_list, char *new_list, int line)
{
    int y = 0;
    int z = 0;
    for (int x = 0; x < line - 1; x++) {
        for (y; new_list[y] != '\n'; y++) {
            final_list[x][z] = new_list[y];
            z++;
        }
        y++;
        z = 0;
    }
    for (int m = 0; new_list[y] != '\0'; m++) {
        final_list[line - 1][m] = new_list[y];
        y++;
    }
}

int my_compute_power_rec(int nb, int power)
{
    if (power == 0) {
        return (1);
    } else if (power < 0) {
        return (0);
    }
    return (nb * my_compute_power_rec(nb, power - 1));
}

char *my_inttostr(int num)
{
    int len = 0; if (num == 0) len++;
    for (int k = num; k != 0; k = k/10, len++);
    char *p = malloc(sizeof(char) * (len + 1));
    p[len] = '\0'; len--;
    for (; len >= 0; len--) {
        p[len] = num % 10 + 48;
        num /= 10;
    }
    return (p);
}

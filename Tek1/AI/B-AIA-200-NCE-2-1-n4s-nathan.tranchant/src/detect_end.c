/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

int detect_track_end(char *str)
{
    int i, j;
    char *newstr;
    if ((newstr = malloc(sizeof(char *) * my_strlen(str))) == NULL)
        return (-1);
    i = my_strlen(str) - 1;
    while (str[i] != ':' && str[i] != 0) i--; i--;
    while (str[i] != ':' && str[i] != 0) i--; i++;
    j = 0;
    while (str[i] != ':' && str[i] != 0) newstr[j++] = str[i++];
    newstr[j] = 0;
    if (my_strcmp("Track Cleared", newstr) == 0) {
        free(newstr);
        exec_cmd("STOP_SIMULATION\n");
        return (1);
    }
    free(newstr);
    return (0);
}

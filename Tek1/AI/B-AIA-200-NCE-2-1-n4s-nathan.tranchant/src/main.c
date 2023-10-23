/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

char *clean_str(char *s)
{
    int a, b;
    char *tmp;
    a = 0, b = 0;
    if ((tmp = malloc(sizeof(char *) * 100)) == NULL) return (NULL);
    while (a != 3) {
        if (s[b++] == ':') a++;
    }
    a = 0;
    while (s[b] != 0) {
        if ((s[b] >= '0' && s[b] <= '9') || s[b] == '.' || s[b] == ':') {
            tmp[a] = s[b];
            a++;
        }
        b++;
    }
    tmp[a - 1] = '\0';
    return (tmp);
}

int change_car_speed(float mid)
{
    int i;
    if (mid >= 2000)
        i = exec_cmd("CAR_FORWARD:1.0\n");
    if (mid < 2000 && mid >= 1500)
        i = exec_cmd("CAR_FORWARD:0.8\n");
    if (mid < 1500 && mid >= 1000)
        i = exec_cmd("CAR_FORWARD:0.5\n");
    if (mid < 1000 && mid >= 600)
        i = exec_cmd("CAR_FORWARD:0.4\n");
    if (mid < 600 && mid >= 400)
        i = exec_cmd("CAR_FORWARD:0.2\n");
    if (mid < 400)
        i = exec_cmd("CAR_FORWARD:0.1\n");
    return (i);
}

int ia(void)
{
    char **tab, *res;
    float midlight;
    while (1) {
        my_putstr("GET_INFO_LIDAR\n", 1);
        res = get_next_line(0);
        if (detect_track_end(res) == 1) break;
        res = clean_str(res);
        tab = str_to_word_array(res, ':');
        midlight = my_strtof(tab[15]);
        if (change_car_speed(midlight) == 1) break;
        my_putstr("GET_INFO_LIDAR\n", 1);
        res = get_next_line(0);
        if (detect_track_end(res) == 1) break;
        res = clean_str(res);
        tab = str_to_word_array(res, ':');
        midlight = my_strtof(tab[15]);
        if (get_direction(tab, midlight) == 1) break;
    } return (0);
}

int main(void)
{
    exec_cmd("START_SIMULATION\n");
    ia();
    return (0);
}

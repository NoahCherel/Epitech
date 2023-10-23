/*
** EPITECH PROJECT, 2022
** ai.H
** File description:
** Includes for need4stek project
*/

#ifndef AI_H
    #define AI_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <sys/types.h>

    typedef struct s_vars {
        int idx;
        int idx_line;
        int value_read;
        char buffer[1];
        char *line;
    } t_vars;

    int ia(void);

    char *get_next_line(const int fd);
    char *clean_str(char *s);
    int detect_track_end(char *str);
    int get_direction(char **tab, float midlight);
    int exec_cmd(char *str);

    void my_putstr(char *str, int fd);
    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    float  my_strtof(char *str);
    char *my_strndup(char *str, int n);
    char **str_to_word_array(char *str, char delim);

#endif

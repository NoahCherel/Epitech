/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

char *get_next_line(const int fd)
{
    static t_vars var;
    if ((var.idx == 0 && (var.value_read = read(fd, var.buffer, 1)) < 1)
        || (var.idx_line == 0 && (var.line = malloc(4096)) == NULL))
        exit(84);
    while (var.idx != var.value_read) {
        if (var.buffer[var.idx] == '\n' || var.buffer[var.idx] == 0) {
            var.idx++;
            var.line[var.idx_line] = 0;
            var.idx_line = 0;
            return (var.line);
        }
        var.line[var.idx_line] = var.buffer[var.idx];
        var.idx_line++;
        var.idx++;
    }
    var.idx = 0;
    get_next_line(fd);
    return (var.line);
}

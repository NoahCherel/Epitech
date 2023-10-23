/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex3
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy (const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len = strlen(this->str);
    if (pos >= len) return 0;
    size_t num_to_copy = (n > len - pos) ? len - pos : n;
    memcpy(s, this->str + pos, num_to_copy);
    if (num_to_copy < n) {
        s[num_to_copy] = '\0';
        return num_to_copy + 1;
    }
    return num_to_copy;
}

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}

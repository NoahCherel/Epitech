/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex4
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *occurrence = strstr(this->str + pos, str->str);
    if (occurrence == NULL) {
        return (-1);
    }
    return (occurrence - this->str);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *occurrence = strstr(this->str + pos, str);
    if (occurrence == NULL) {
        return (-1);
    }
    return (occurrence - this->str);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp = malloc(strlen(this->str) + strlen(str) + 1);
    strncpy(tmp, this->str, pos);
    tmp[pos] = '\0';
    strcat(tmp, str);
    strcat(tmp, this->str + pos);
    free(this->str);
    this->str = tmp;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *tmp = malloc(strlen(this->str) + strlen(str->str) + 1);
    strncpy(tmp, this->str, pos);
    tmp[pos] = '\0';
    strcat(tmp, str->str);
    strcat(tmp, this->str + pos);
    free(this->str);
    this->str = tmp;
}

int to_int(const string_t *this)
{
    return (atoi(this->str));
}

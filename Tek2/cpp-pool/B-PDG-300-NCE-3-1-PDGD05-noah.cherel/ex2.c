/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = malloc(strlen(this->str) + strlen(ap->str) + 1);
    strcpy(tmp, this->str);
    strcat(tmp, ap->str);
    free(this->str);
    this->str = tmp;
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = malloc(strlen(this->str) + strlen(ap) + 1);
    strcpy(tmp, this->str);
    strcat(tmp, ap);
    free(this->str);
    this->str = tmp;
}

char at(const string_t *this, size_t pos)
{
    if (pos >= strlen(this->str))
        return (-1);
    return (this->str[pos]);
}

void clear(string_t *this)
{
    free(this->str);
    this->str = malloc(1);
    this->str[0] = '\0';
}

int length(const string_t *this)
{
    if (this == NULL)
        return (-1);
    return (strlen(this->str));
}

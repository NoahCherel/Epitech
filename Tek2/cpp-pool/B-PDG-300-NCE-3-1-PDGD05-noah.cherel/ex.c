/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = malloc(strlen(s) + 1);
    strcpy(this->str, s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    free(this->str);
    this->str = malloc(strlen(str->str) + 1);
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = malloc(strlen(s) + 1);
    strcpy(this->str, s);
}

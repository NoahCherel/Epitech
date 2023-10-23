/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** size
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;
    linked_list_t *current;
    current= begin;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return (size);
}

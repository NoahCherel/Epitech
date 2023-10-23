/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    unsigned int i = 0;
    queue_t tmp = queue;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

bool queue_is_empty(queue_t queue)
{
    if (queue == NULL)
        return (true);
    return (false);
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    queue_t new = malloc(sizeof(*new));
    queue_t tmp = *queue_ptr;

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = NULL;
    if (*queue_ptr == NULL) {
        *queue_ptr = new;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return (true);
}

bool queue_pop(queue_t *queue_ptr)
{
    queue_t tmp = *queue_ptr;

    if (queue_is_empty(*queue_ptr))
        return (false);
    *queue_ptr = tmp->next;
    free(tmp);
    return (true);
}

void queue_clear(queue_t *queue_ptr)
{
    queue_t tmp = *queue_ptr;

    while (tmp != NULL) {
        tmp = tmp->next;
        free(*queue_ptr);
        *queue_ptr = tmp;
    }
}

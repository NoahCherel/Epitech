/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex030
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

void *queue_front(queue_t queue)
{
    if (queue == NULL)
        return (NULL);
    return (queue->value);
}

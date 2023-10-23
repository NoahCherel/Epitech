/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** queue2
*/

#include "../inc/server.h"

void requeue(command_queue_t* queue, command_queue_item_t item_requeued)
{
    queue->rear = (queue->rear + 1) % 1000;
    command_queue_item_t item;
    item.command = strdup(item_requeued.command);
    item.sockfd = item_requeued.sockfd;
    item.timer = item_requeued.timer;
    queue->queue[queue->rear] = item;
    queue->size++;
}

command_queue_item_t dequeue(command_queue_t* queue)
{
    if (is_queue_empty(queue)) {
        command_queue_item_t empty_item = { "", -1 , 0};
        return empty_item;
    }

    command_queue_item_t item = queue->queue[queue->front];
    queue->front = (queue->front + 1) % 1000;
    queue->size--;
    return item;
}

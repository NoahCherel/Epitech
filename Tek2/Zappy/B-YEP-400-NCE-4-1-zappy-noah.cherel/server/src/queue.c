/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** queue
*/

#include "../inc/server.h"

void initialize_queue(command_queue_t* queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

bool is_queue_empty(const command_queue_t* queue)
{
    return queue->size == 0;
}

bool is_queue_full(const command_queue_t* queue)
{
    return queue->size == 1000;
}

void display_queue(const command_queue_t* queue)
{
    if (is_queue_empty(queue)) {
        printf("Command queue is empty\n");
        return;
    }

    int current_index = queue->front;
    int count = 0;

    while (count < queue->size) {
        command_queue_item_t item = queue->queue[current_index];
        printf("Item %d: Command: %s, Socket: %d, Timer: %d", count + 1,
        item.command, item.sockfd, item.timer);
        current_index = (current_index + 1) % 1000;
        count++;
    }
}

void enqueue(command_queue_t* queue, char* command, int sockfd, game_t* game)
{
    int timer = 0;
        if (is_queue_full(queue)) {
            printf("Command queue is full\n");
            return;
        }
        if (strcmp(command, "Forward") == 0 || strcmp(command, "Right") == 0
        || strcmp(command, "Left") == 0 || strcmp(command, "Look") == 0
        || strcmp(command, "Take") == 0 || strcmp(command, "Set") == 0
        || strcmp(command, "Broadcast") == 0) {
            timer = 7 / game->freq;
        }
        if (strcmp(command, "Inventory") == 0) timer = 1 / game->freq;
        if (strcmp(command, "Incantation") == 0) timer =  300 / game->freq;
        if (strcmp(command, "Fork") == 0) timer = 42 / game->freq;
        timer += get_current_time();
    queue->rear = (queue->rear + 1) % 1000; command_queue_item_t item;
    item.command = strdup(command); item.sockfd = sockfd; item.timer = timer;
    queue->queue[queue->rear] = item;
    queue->size++;
}

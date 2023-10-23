/*
** EPITECH PROJECT, 2021
** btree
** File description:
** task02
*/
#include <stdlib.h>
#include "include/my.h"

btree_t *btree_create_node(void *item)
{
    struct node* node = malloc(sizeof(struct node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

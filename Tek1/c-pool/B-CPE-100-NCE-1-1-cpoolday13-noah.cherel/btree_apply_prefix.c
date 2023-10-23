/*
** EPITECH PROJECT, 2021
** btree_apply_prefix
** File description:
** task02
*/
#include <stdlib.h>
#include "include/my.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    btree_t * currentL = root;
    btree_t * currentR = root;
        while (currentL->left != NULL | currentR->right != NULL) {
        (*applyf)(currentL->data);
        (*applyf)(currentR->data);
        currentL = currentL->data;
        currentR = currentR->data;
    }
    return (0);
}

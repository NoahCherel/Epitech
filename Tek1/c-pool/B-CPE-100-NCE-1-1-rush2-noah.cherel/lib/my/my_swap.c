/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** functions that swaps the content of two integer
*/

void my_swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

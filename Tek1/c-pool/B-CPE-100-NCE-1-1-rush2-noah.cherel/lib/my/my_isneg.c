/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** displays if neg
*/

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    }
    else {
        my_putchar('P');
    }
    my_putchar('\n');
}

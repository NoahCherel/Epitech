/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** function that displays one by one the character of a string
*/

int my_putstr(char const *str)
{
    while (*str != '\0')
    {
        my_putchar(*str);
        str = str + 1;
    }
}

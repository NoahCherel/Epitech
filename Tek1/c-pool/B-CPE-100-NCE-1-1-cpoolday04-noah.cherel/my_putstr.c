/*
** EPITECH PROJECT, 2021
** My_putstr
** File description:
** Task02
*/
#include <unistd.h>
#include <string.h>

int my_putstr(char const *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}

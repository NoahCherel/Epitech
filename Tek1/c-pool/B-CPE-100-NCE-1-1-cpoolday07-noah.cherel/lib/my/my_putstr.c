/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** putstr
*/

void my_putchar(char c);

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

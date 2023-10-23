/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int a = 1;
    while (('-' == (*str)) || ((*str) == '+'))
    {
        if (*str == '-')
            a = a* (-1);
        str++;
    }
    while ((*str >= '0') && (*str <= '9'))
    {
        nb = (nb *10) + ((str) - '0');
        str++;
    }
    return (nb *a);
}

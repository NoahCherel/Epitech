/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** Function that copies a string into another for a limit n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int cpy;

    if (n <= 0)
        return (0);
    for (cpy = 0; cpy < n; cpy++)
        dest[cpy] = src[cpy];
    dest[cpy] = '\0';
    return (dest);
}

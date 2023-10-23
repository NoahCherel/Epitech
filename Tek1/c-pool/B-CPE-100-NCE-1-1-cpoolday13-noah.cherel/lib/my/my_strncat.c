/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len;
    len = my_strlen(dest);
    int i;
    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[len + 1] = src[i];
    dest[len + 1] = '\0';
    return (dest);
}

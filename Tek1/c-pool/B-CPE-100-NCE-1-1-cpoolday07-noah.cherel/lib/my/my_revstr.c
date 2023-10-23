/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** rev
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i;
    int len;
    int a;
    len = my_strlen(str);
    for (i = 0; i < len/2; i++) {
        a = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = a;
    }
    return (str);
}

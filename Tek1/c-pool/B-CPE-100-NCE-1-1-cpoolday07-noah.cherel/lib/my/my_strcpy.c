/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** strcpy
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int len2 = my_strlen(src);
    int i;
    while (i < len || i < len2) {
        if (i <= len2) {
            dest[i] = src[i];
            i++;
        }
        else {
            dest[i] = '\0';
            i++;
        }
    }
    return (dest);
}

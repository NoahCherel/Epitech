/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int destlen = my_strlen(dest);
    while (src[i] != '\0') {
        dest[destlen + i] = src[i];
        i++;
    }
    dest[destlen + i] = '\0';
    return dest;
}

/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** strncpy
*/

void *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
        if (i < 0) {
            i++;
            dest[i] = '\0';
        }
    }
    return (dest);
}

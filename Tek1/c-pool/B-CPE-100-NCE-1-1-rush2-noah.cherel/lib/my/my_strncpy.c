/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** function that copy n character to dest string
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i + 1 == n) {
        dest[i] = '\0';
    }
    return (dest);
}

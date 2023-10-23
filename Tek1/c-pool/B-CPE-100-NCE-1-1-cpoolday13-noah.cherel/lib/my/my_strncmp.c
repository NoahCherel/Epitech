/*
** EPITECH PROJECT, 2021
** strncmp
** File description:
** cmp
*/

int my_strncmp(char const *s1,char const *s2, int n)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i + 1 < n) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
}


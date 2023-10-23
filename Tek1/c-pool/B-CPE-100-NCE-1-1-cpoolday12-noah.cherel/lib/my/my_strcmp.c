/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0') {
     	if (s1[i] != s2[i]) {
            return (s2[i] - s1[i]);
        }
        i++;
    }
    return (0);
}

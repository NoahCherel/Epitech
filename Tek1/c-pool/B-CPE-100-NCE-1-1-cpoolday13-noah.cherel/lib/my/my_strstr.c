/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(to_find);
    if (str[0] == '\0') {
        return (0);
    }
    while (to_find[i] != '\0') {
        if (my_strncmp(str, to_find, len) == 0) {
            return (str);
        }
        return my_strstr(str + 1, to_find);
    }
}

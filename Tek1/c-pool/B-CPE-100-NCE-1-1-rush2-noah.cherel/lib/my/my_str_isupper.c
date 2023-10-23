/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** is lower
*/

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return 1;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return 0;
    }
    return 1;
}

/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** check if there is only alphabetical in the string
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return 1;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126)
            i++;
        else
            return 0;
    }
    return 1;
}

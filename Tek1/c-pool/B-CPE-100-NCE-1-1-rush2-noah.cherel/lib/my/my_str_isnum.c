/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** digit string check
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return 1;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;

    }
    return 1;
}

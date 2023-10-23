/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** lower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            i++;
        } else {
            return (0);
        }
    }
    return(1);
}

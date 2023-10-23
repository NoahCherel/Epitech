/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** upper
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            i++;
        } else {
            return (0);
        }
    }
    return(1);
}


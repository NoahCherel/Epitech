/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** alpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            i++;
        } else {
            return (0);
        }
    }
    return(1);
}

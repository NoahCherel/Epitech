/*
** EPITECH PROJECT, 2021
** str_capitalize
** File description:
** capitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;
    if (str[0] >= 97 && str[0] <= 122) {
        str[0] = str[0] - 32;
    }
    while (str[i] != '\0') {
        if ((str[i - 1] >= 23 && str{i - 1] <= 47) || str[i - 1] <= ';') {
            if (str[i] <= 'z' && str[i] >= 'a') {
                str[i] = str[i] - 32;
            }
        }
        i++;
    }
    return (str);
}

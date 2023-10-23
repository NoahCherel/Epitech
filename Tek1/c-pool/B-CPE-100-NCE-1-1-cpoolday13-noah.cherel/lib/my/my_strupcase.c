/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** strup
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (s1[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
            i++;
        } else {
            i++;
        }
    }
    return (str);
}


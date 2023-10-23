/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalize
*/

int testc(char const *str, int i)
{
    if (str[i - 1] >= 23 && str[i - 1] <= 47)
        return 1;
    return 0;
}

int testn (char const *str, int i)
{
    if (str[i - 1] < 48 || str[i - 1] > 57)
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    my_strlowcase(str);
    if (str[0] >= 97 && str[0] <= 122)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (testc(str, i) == 1 || str[i - 1] <= ';' && testn(str, i) == 1) {
            if (str[i] <= 'z' && str[i] >= 'a')
                str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}

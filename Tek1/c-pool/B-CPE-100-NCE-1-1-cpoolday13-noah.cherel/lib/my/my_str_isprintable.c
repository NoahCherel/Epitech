/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126){
            i++;
        } else {
            return (0);
        }
    }
    return(1);
}

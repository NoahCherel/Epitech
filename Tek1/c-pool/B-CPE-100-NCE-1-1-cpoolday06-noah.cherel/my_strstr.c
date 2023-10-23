*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** task05
*/
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return(i);
}

int my_strncmp(char const *s1,char const *s2, int n)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i + 1 < n) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(to_find);
    if (str[0] == '\0') {
        return (0);
    }
    while (to_find[i] != '\0') {
        if (my_strncmp(str, to_find, len) == 0) {
            return (str);
        }
        return my_strstr(str + 1, to_find);
    }
}

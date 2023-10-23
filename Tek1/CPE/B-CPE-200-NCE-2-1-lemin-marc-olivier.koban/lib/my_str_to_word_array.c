/*
** EPITECH PROJECT, 2021
** MY_STR_TO_WORD_ARRAY
** File description:
** Function that splits a string into words
*/

#include "../include/my.h"

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

int is_separator(char c, char sep)
{
    if (c == '\0')
        return (0);
    if (c >= 32 && c <= 126 && c != sep)
        return (1);
    return (0);
}

int count_words(char const *str, char sep)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (is_separator(str[i], sep) && !(is_separator(str[i + 1], sep)))
            count++;
    }
    return (count);
}

char **my_str_to_word_array(char const *str, char sep)
{
    char **word_array = malloc(sizeof(char *) * (count_words(str, sep) + 1));
    int j = 0, wordlen = 0;

    if (!(word_array))
        return (0);
    for (int i = 0; str[i]; i++) {
        if (is_separator(str[i], sep))
            wordlen++;
        if (is_separator(str[i], sep) && !(is_separator(str[i + 1], sep))) {
            word_array[j] = malloc(sizeof(char) * (wordlen + 1));
            my_strncpy(word_array[j], &str[i - wordlen + 1], wordlen);
            wordlen = 0;
            j++;
        }
    }
    word_array[j] = '\0';
    return (word_array);
}

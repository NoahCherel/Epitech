/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** str_to_word
*/

#include <stdlib.h>

int my_strlen(char const *str);

int get_word_count(char const *str)
{
    int new_word = 1;
    int word_count = 0;
    int strlength = my_strlen(str);
    for (int i = 0; i < strlength; i++) {
        if (str[i] < 48 || str[i] > 122) {
            new_word = 1;
        } else if (new_word == 1) {
            new_word = 0;
            word_count++;
        }
    }
    return (word_count);
}

char **crt_arr(char const *str, int word_count, int strlength)
{
    int j = 0, checkpoint = 0, new_word = 1, i, k;
    char **word_array = malloc(strlength + 1);
    for (int i = 0; i <= strlength; i++) {
        if (str[i] < 48 || str[i] > 122 || i == strlength) {
            new_word = 1;
            word_array[j] = malloc((i - checkpoint));
            for (k = checkpoint; k < i; k++) {
                word_array[j][k - checkpoint] = str[k];
            }
            word_array[j][i - checkpoint] = '\0';
            j++;
        } else if (new_word == 1) {
            new_word = 0;
            checkpoint = i;
        }
    }
    return (word_array);
    free (word_array);
}

char **my_str_to_word_array(char const *str)
{
    int word_count = get_word_count(str);
    int strlength = my_strlen(str);
    char **word_array = crt_arr(str, word_count, strlength);
    word_array[word_count] = malloc(1);
    word_array[word_count] = '\0';
    return (word_array);
}

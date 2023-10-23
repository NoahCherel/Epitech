/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sort
*/

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int tmp = 0;
    while (i != size) {
        if (i > 0 && tab[i] < tab[i - 1]) {
            tmp = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = tmp;
            i = i - 2;
        }
        i++;
    }
    return (tab);
}

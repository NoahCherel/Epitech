/*
** EPITECH PROJECT, 2021
** frequencies
** File description:
** frequencies of each letter
*/

#include "include/my.h"

void display(char ocout, int a, float res);

void my_put_float(double fnb)
{
    int nb = fnb;
    my_put_nbr(nb);
    my_putchar('.');
    my_put_nbr((fnb-nb)*100);
    if (fnb - nb == 0)
        my_putchar('0');
}

int my_isal(char b)
{
    if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
        return 1;
    else
        return 0;
}

int frequencies(int argc, char const **argv)
{
    int a = 0;
    int b = 0;
    char *str = my_strlowcase(argv[1]);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isal(str[i]) == 1)
            b++;
    }
    for (int i = 2; i != argc; i++) {
        char ocout = argv[i][0];
        char *oc = my_strlowcase(argv[i]);
        for (int k = 0; str[k] != '\0'; k++) {
            if (str[k] == oc[0])
            a++;
        }
        float res = (float)(100 * a) / b;
        display(ocout, a, res);
        a = 0;
    }
}

void display(char ocout, int a, float res)
{
    my_putchar(ocout);
    my_putchar(':');
    my_put_nbr(a);
    my_putchar(' ');
    my_putchar('(');
    my_put_float(res);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');

}

int main (int argc, char const **argv)
{
    frequencies(argc, argv);
    my_putchar('\n');
}

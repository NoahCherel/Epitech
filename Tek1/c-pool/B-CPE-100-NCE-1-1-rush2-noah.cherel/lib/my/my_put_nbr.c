/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the number given as parameter
*/

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10){
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    else{
        my_putchar(nb + '0');
    }
}

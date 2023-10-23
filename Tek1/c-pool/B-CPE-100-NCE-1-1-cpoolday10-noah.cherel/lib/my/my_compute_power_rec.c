/*
** EPITECH PROJECT, 2021
** my_computer_power_rec
** File description:
** my_compute_power_j
*/

int my_compute_power_rec(int nb, int power)
{
    if (power < 0) {
        return (1);
    }
    if (nb == 0) {
        return (0);
    }
    power = power - 1;
    nb = nb * my_compute_power_rec(nb, power - 1);
    return (nb);
}

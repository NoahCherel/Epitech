/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** prime_sup
*/

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}

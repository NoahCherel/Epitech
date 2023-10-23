#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## build.sh
## File description:
## task01
##

gcc -c my_putchar.c
gcc -c my_isneg.c
gcc -c my_put_nbr.c
gcc -c my_swap.c
gcc -c my_putstr.c
gcc -c my_strlen.c
gcc -c my_getnbr.c
gcc -c my_sort_int_array.c
gcc -c my_compute_power_rec.c
gcc -c my_compute_square_root.c
gcc -c my_is_prime.c
gcc -c my_find_prime_sup.c
gcc -c my_strcpy.c
gcc -c my_strncpy.c
gcc -c my_revstr.c
gcc -c my_strstr.c
gcc -c my_strcmp.c
gcc -c my_strncmp.c
gcc -c my_strupcase.c
gcc -c my_strlowcase.c
gcc -c my_strcapitalize.c
gcc -c my_str_isalpha.c
gcc -c my_str_isnum.c
gcc -c my_str_islower.c
gcc -c my_str_isupper.c
gcc -c my_str_isprintable.c
gcc -c my_showstr.c
gcc -c my_showmem.c
gcc -c my_strcat.c
gcc -c my_strncat.c
gcc -c my_str_to_word_array.c
gcc -c my_show_word_array.c
ar rc libmy.a *.o

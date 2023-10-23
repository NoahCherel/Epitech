/*
** EPITECH PROJECT, 2021
** test_my_strncpy
** File description:
** task04
*/
#include <criterion/criterion.h>

Test(my_revstr, reverse_characters_in_string)
{
    my_revstr("HelloWorld");
    cr_assert_str_eq(str, "dlroWolleH");
}


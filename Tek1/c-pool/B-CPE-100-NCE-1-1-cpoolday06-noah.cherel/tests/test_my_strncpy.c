/*
** EPITECH PROJECT, 2021
** test_my_revstr
** File description:
** task05
*/

#include <criterion/criterion.h>

Test(my_strncpy , copy_five_characters_in_empty_array)
{
    char dest [6] = {0};

    my_strncpy(dest , "HelloWorld", 5);
    cr_assert_str_eq(dest , "Hello");
}

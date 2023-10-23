#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## build.sh
## File description:
## build my lib
##

gcc -c *.c
ar rc libmy.a *.o

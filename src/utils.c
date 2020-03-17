/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utils source file
*/

#include "../include/my_runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        ++i;
    }
}
/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** mini printf
*/

#include "includes/my.h"

void my_put_nbr(int c)
{
    if (c > 9) {
    my_put_nbr(c / 10);
    }
    my_putchar(c % 10 + '0');
}

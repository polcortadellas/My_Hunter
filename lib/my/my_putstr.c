/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** project.c
*/
#include "includes/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

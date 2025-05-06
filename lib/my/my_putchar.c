/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** project.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

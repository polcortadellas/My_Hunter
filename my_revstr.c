    /*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** task 05 day 5 find square root
*/
#include "includes/my_hunter.h"
#include <unistd.h>
#include <stdio.h>

char *my_revstr(char *str)
{
    int i;
    int length = 0;
    int a;
    char temp;

    for (a = 0; str[a] != '\0'; a++) {
        length++;
    }
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

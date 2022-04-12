/*
** EPITECH PROJECT, 2021
** my_getstr.c
** File description:
** convert int to str
*/

#include <stdlib.h>
#include "my.h"

int my_nbrlen(int nb)
{
    int len = 1;

    if (nb < 0)
        len++;
    for (;nb / 10 != 0; len++)
        nb /= 10;
    return len;
}

char *my_revstr(char *str)
{
    char temp;

    for (int i = 0, j = my_strlen(str) - 1; i < j; i += 1, j -= 1) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
    return str;
}

char *fill_str(char *str, int nb, int *pos)
{
    while (nb >= 10) {
        str[pos[0]] = nb % 10 + '0';
        pos[0]++;
        nb /= 10;
    }
    if (nb < 10) {
        str[pos[0]] = nb + '0';
        pos[0]++;
    }
    return str;
}

char *my_getstr(int nb)
{
    char *str = malloc(sizeof(char) * my_nbrlen(nb) + 1);
    int pos = 0;
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    fill_str(str, nb, &pos);
    if (neg == 1) {
        str[pos] = '-';
        pos++;
    }
    str[pos] = '\0';
    return my_revstr(str);
}

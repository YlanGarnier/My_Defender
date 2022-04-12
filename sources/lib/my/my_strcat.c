/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my strcat description
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *str1, char const *str2)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));

    str = my_strcpy(str, str1);
    if (str[0] != '\0')
        i = my_strlen(str);
    else
        i = 0;
    for (int y = 0; str2[y] != '\0'; i++, y++)
        str[i] = str2[y];
    str[i] = ' ';
    str[i + 1] = '\0';
    return str;
}

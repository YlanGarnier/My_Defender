/*
** EPITECH PROJECT, 2022
** my_is_alpha.c
** File description:
** is caracter alpha
*/

int is_alpha(char c)
{
    if (c > 31 && c < 127)
        return 0;
    return 1;
}

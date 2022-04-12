/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

int main(int ac, char **av)
{
    if (ac == 2 && (my_strcmp(av[1], "-h") == 1 ||
my_strcmp(av[1], "--help") == 1))
        return usage();
    if (error_handling(ac) == ERROR)
        return ERROR;
    return defender();
}

/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** return 84 if error detected, 0 if not
*/

#include <unistd.h>
#include "my_macro.h"

int error_handling(int ac)
{
    if (ac != 1) {
        write(2, "You don't need to put any flags to play.\n", 41);
        return ERROR;
    }
    return 0;
}

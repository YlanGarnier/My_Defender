/*
** EPITECH PROJECT, 2022
** intro.c
** File description:
** intro
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

void intro(window_t *window, menu_t *menu)
{
    sfMusic_play(window->sound[0].music);
    menu->clock.time = sfClock_getElapsedTime(menu->clock.clock);
    if (menu->clock.time.microseconds >= 500000) {
        sfClock_restart(menu->clock.clock);
        menu->state = BASE;
    }
    return;
}

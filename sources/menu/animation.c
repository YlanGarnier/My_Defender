/*
** EPITECH PROJECT, 2022
** animation.c
** File description:
** sroll animation
*/

#include "my_defender.h"
#include "my_macro.h"
#include "menu.h"

void set_scroll_animation(menu_t *menu)
{
    static int left = 0;

    menu->clock.time = sfClock_getElapsedTime(menu->clock.clock);
    if (menu->clock.time.microseconds >= 50000) {
        if (left == 0)
            menu->animation = 2;
        if (menu->animation == 1)
            left -= 253;
        else if (menu->animation == 2)
            left += 253;
        if (left == 1012)
            menu->animation = 0;
        menu->board.rect = get_rect(285, 253, 0, left);
        sfSprite_setTextureRect(menu->board.sprite, menu->board.rect);
        sfClock_restart(menu->clock.clock);
    }
    return;
}

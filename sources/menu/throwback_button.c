/*
** EPITECH PROJECT, 2022
** throwback_button.c
** File description:
** when you made a mistake :)
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

int is_mouse_over_back(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 1065 &&
    window->event.mouseButton.x <= 1150) && (window->event.mouseButton.y >= 370
    && window->event.mouseButton.y <= 430) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 1065 &&
    window->event.mouseMove.x <= 1150) && (window->event.mouseMove.y >= 370
    && window->event.mouseMove.y <= 430))
        return POINT;
    return FALSE;
}

void set_throwback_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_back(window, menu) == POINT) {
        sfSprite_setScale(menu->throwback.sprite, set_scale(0.15, 0.15));
        sfSprite_setTextureRect(menu->throwback.sprite,
        get_rect(512, 512, 0, 512));
        sfSprite_setPosition(menu->throwback.sprite, get_offset(1055, 360));
    } else if (is_mouse_over_back(window, menu) == CLICK) {
        menu->state = BASE;
        menu->animation = 1;
    } else {
        sfSprite_setScale(menu->throwback.sprite, set_scale(0.1, 0.1));
        sfSprite_setTextureRect(menu->throwback.sprite,
        get_rect(512, 512, 0, 0));
        sfSprite_setPosition(menu->throwback.sprite, get_offset(1065, 370));
    }
    return;
}

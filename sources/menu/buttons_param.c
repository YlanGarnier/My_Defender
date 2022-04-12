/*
** EPITECH PROJECT, 2022
** buttons_param.c
** File description:
** buttons parameters
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

int is_mouse_over_quit(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 950) && (window->event.mouseButton.y >= 700
    && window->event.mouseButton.y <= 800) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 950) && (window->event.mouseMove.y >= 700
    && window->event.mouseMove.y <= 800))
        return POINT;
    return 0;
}

int is_mouse_over_leader(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 1120) && (window->event.mouseButton.y >= 600
    && window->event.mouseButton.y <= 700) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 1120) && (window->event.mouseMove.y >= 600
    && window->event.mouseMove.y <= 700))
        return POINT;
    return 0;
}

int is_mouse_over_settings(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 1050) && (window->event.mouseButton.y >= 500
    && window->event.mouseButton.y <= 600) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 1050) && (window->event.mouseMove.y >= 500
    && window->event.mouseMove.y <= 600))
        return POINT;
    return 0;
}

int is_mouse_over_play(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 950) && (window->event.mouseButton.y >= 400
    && window->event.mouseButton.y <= 500) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 950) && (window->event.mouseMove.y >= 400
    && window->event.mouseMove.y <= 500))
        return POINT;
    return 0;
}

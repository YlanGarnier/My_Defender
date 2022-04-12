/*
** EPITECH PROJECT, 2022
** set_settings_buttons.c
** File description:
** settings buttons but they do something
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

int is_mouse_over_framerate(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 1120) && (window->event.mouseButton.y >= 500
    && window->event.mouseButton.y <= 650) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 1120) && (window->event.mouseMove.y >= 500
    && window->event.mouseMove.y <= 580))
        return POINT;
    return FALSE;
}

int is_mouse_over_volume(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= (menu->parameters.volume_x) &&
    window->event.mouseButton.x <= menu->parameters.volume_x + 20)
    && (window->event.mouseButton.y >= 750
    && window->event.mouseButton.y <= 810) && menu->test == 1)
        return CLICK;
    return FALSE;
}

void set_framerate_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_framerate(window, menu) == POINT)
        sfText_setOutlineThickness
        (menu->settings[menu->parameters.framerate].font.text, 5);
    else if (is_mouse_over_framerate(window, menu) == CLICK) {
        if (menu->parameters.framerate == 0)
        sfRenderWindow_setFramerateLimit(window->window, 60);
        if (menu->parameters.framerate == 1)
        sfRenderWindow_setFramerateLimit(window->window, 120);
        if (menu->parameters.framerate == 2)
        sfRenderWindow_setFramerateLimit(window->window, 30);
        menu->parameters.framerate += 1;
        if (menu->parameters.framerate == 3)
            menu->parameters.framerate = 0;
    } else
        sfText_setOutlineThickness
        (menu->settings[menu->parameters.framerate].font.text, 0);
    return;
}

void set_volume_soundbar(window_t *window, menu_t *menu)
{
    static int condition = 0;
    static int x = 0;
    if (menu->test == 1 && condition == 0 && is_mouse_over_volume(window,
    menu) == CLICK) {
        x = window->event.mouseButton.x;
        condition = 1;
    }
    if (condition == 1) {
        x = lower_volume(window, menu, x);
        x = up_volume(window, menu, x);
    }
    if (menu->parameters.release == 1 && condition == 1)
        condition = 0;
    return;
}

void set_settings_buttons(window_t *window, menu_t *menu)
{
    set_framerate_button(window, menu);
    set_volume_soundbar(window, menu);
    return;
}

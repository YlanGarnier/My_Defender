/*
** EPITECH PROJECT, 2022
** display_wheel.c
** File description:
** display wheel
*/

#include "my_defender.h"
#include "menu.h"

void move_wheel_down(window_t *window, menu_t *menu)
{
    if (menu->map[0].y < 420)
        for (int i = 0; i != window->map_nb; i++) {
            menu->map[i].y += 75;
            sfText_setPosition(menu->map[i].font.text,
            get_offset(800, menu->map[i].y));
        }
    return;
}

void move_wheel_up(window_t *window, menu_t *menu)
{
    if (menu->map[window->map_nb - 1].y >= 800)
        for (int i = 0; i != window->map_nb; i++) {
            menu->map[i].y -= 75;
            sfText_setPosition(menu->map[i].font.text,
            get_offset(800, menu->map[i].y));
        }
    return;
}

void set_wheel(window_t *window, menu_t *menu)
{
    if (window->event.mouseWheelScroll.delta) {
        if (window->event.mouseWheelScroll.delta > 0)
            move_wheel_down(window, menu);
        else if (window->event.mouseWheelScroll.delta < 0)
            move_wheel_up(window, menu);
    }
    return;
}

/*
** EPITECH PROJECT, 2022
** wheel_param.c
** File description:
** map wheel parameters
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

int is_mouse_over_a_map(window_t *window, menu_t *menu, int i)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 1100) &&
    (window->event.mouseButton.y >= menu->map[i].y
    && window->event.mouseButton.y <= (menu->map[i].y + 75))
    && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
        window->event.mouseMove.x <= 1100) &&
        (window->event.mouseMove.y >= menu->map[i].y
        && window->event.mouseMove.y <= (menu->map[i].y + 75)))
        return POINT;
    return FALSE;
}

void set_map_selection(window_t *window, menu_t *menu)
{
    for (int i = 0; i != window->map_nb; i++)
        if (is_mouse_over_a_map(window, menu, i) == POINT)
            sfText_setOutlineThickness(menu->map[i].font.text, 5);
        else if (is_mouse_over_a_map(window, menu, i) == CLICK) {
            sfMusic_stop(window->sound[0].music);
            window->which_map = i;
            window->state = GAME;
            menu->state = BASE;
        }
        else
            sfText_setOutlineThickness(menu->map[i].font.text, 0);
    return;
}

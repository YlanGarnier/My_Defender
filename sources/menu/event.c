/*
** EPITECH PROJECT, 2022
** event.c
** File description:
** event
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

void what_to_check(window_t *window, menu_t *menu)
{
    set_menu_sprites(window, menu);
    if (menu->state == BASE)
        set_menu_buttons(window, menu);
    if (menu->state == MAPS && menu->animation == 0)
        set_map_selection(window, menu);
    if (menu->state == SETTINGS && menu->animation == 0)
        set_settings_buttons(window, menu);
    return;
}

void check_event(window_t *window, menu_t *menu)
{
    if (window->event.type == sfEvtMouseWheelScrolled && menu->state == MAPS)
        set_wheel(window, menu);
    else if (window->event.type == sfEvtMouseMoved
    || window->event.type == sfEvtMouseButtonPressed)
        what_to_check(window, menu);
    display_cursor(window);
    return;
}

int check_click(window_t *window)
{
    if (window->event.type == sfEvtMouseButtonPressed)
        return 1;
    return 0;
}

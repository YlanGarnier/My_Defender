/*
** EPITECH PROJECT, 2022
** set_buttons.c
** File description:
** set buttons ide
*/

#include "my_defender.h"
#include "my_macro.h"
#include "menu.h"

void set_menu_play_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_play(window, menu) == POINT)
        sfText_setOutlineThickness(menu->play_button.font.text, 5);
    else if (is_mouse_over_play(window, menu) == CLICK) {
        menu->state = MAPS;
        menu->animation = 1;
    } else
        sfText_setOutlineThickness(menu->play_button.font.text, 0);
    return;
}

void set_menu_settings_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_settings(window, menu) == POINT)
        sfText_setOutlineThickness(menu->settings_button.font.text, 5);
    else if (is_mouse_over_settings(window, menu) == CLICK) {
        menu->state = SETTINGS;
        menu->animation = 1;
    } else
        sfText_setOutlineThickness(menu->settings_button.font.text, 0);
    return;
}

void set_menu_leader_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_leader(window, menu) == POINT)
        sfText_setOutlineThickness(menu->leader_button.font.text, 5);
    else if (is_mouse_over_leader(window, menu) == CLICK)
        printf("leader\n");
    else
        sfText_setOutlineThickness(menu->leader_button.font.text, 0);
    return;
}

void set_menu_quit_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_quit(window, menu) == POINT)
        sfText_setOutlineThickness(menu->quit_button.font.text, 5);
    else if (is_mouse_over_quit(window, menu) == CLICK)
        sfRenderWindow_close(window->window);
    else
        sfText_setOutlineThickness(menu->quit_button.font.text, 0);
    return;
}

void set_menu_buttons(window_t *window, menu_t *menu)
{
    set_menu_play_button(window, menu);
    set_menu_settings_button(window, menu);
    set_menu_leader_button(window, menu);
    set_menu_quit_button(window, menu);
    set_menu_help_button(window, menu);
    return;
}

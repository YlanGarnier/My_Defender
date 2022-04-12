/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** game menu
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

void analyse_menu_events(window_t *window, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtMouseButtonPressed) {
            menu->test = 1;
            menu->parameters.release = 0;
        }
        if (window->event.type == sfEvtMouseButtonReleased) {
            menu->parameters.release = 1;
        }
        check_event(window, menu);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
    menu->test = 0;
    return;
}

void display_menu(window_t *window, menu_t *menu)
{
    display_sprites(window, menu);
    if (menu->state == BASE && menu->animation == 0)
        display_buttons(window, menu);
    if (menu->state == MAPS && menu->animation == 0)
        display_maps(window, menu);
    if (menu->state == SETTINGS && menu->animation == 0)
        display_settings(window, menu);
    if (menu->state == HELP && menu->animation == 0)
        sfRenderWindow_drawText(window->window,
        menu->help_button[1].font.text, NULL);
    sfRenderWindow_drawSprite(window->window, window->cursor.sprite, NULL);
    return;
}

void menu_functions(window_t *window, menu_t *menu)
{
    sfRenderWindow_clear(window->window, sfBlack);
    if (menu->state == INTRO)
        intro(window, menu);
    analyse_menu_events(window, menu);
    display_menu(window, menu);
    sfRenderWindow_display(window->window);
    return;
}

menu_t set_menu(window_t *window)
{
    menu_t menu;

    menu.clock.clock = sfClock_create();
    menu.state = INTRO;
    menu.animation = 2;
    menu.parameters.framerate = 1;
    menu.parameters.volume_x = 1110;
    menu.parameters.volume_rect_x = 320;
    get_buttons(&menu);
    get_settings_buttons(&menu);
    get_sprites(&menu);
    get_maps_wheel(window, &menu);
    get_help_button(&menu);
    return menu;
}

/*
** EPITECH PROJECT, 2022
** settings_buttons.c
** File description:
** settings buttons
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"
#include <stdlib.h>

void display_settings(window_t *window, menu_t *menu)
{
    sfRenderWindow_drawText
(window->window, menu->settings[menu->parameters.framerate].font.text, NULL);
    sfRenderWindow_drawText
    (window->window, menu->settings[3].font.text, NULL);
    sfRenderWindow_drawRectangleShape
    (window->window, menu->settings[4].rect, NULL);
    sfRenderWindow_drawRectangleShape
    (window->window, menu->settings[5].rect, NULL);
    sfRenderWindow_drawSprite
    (window->window, menu->settings[4].sprite.sprite, NULL);
    return;
}

font_t get_setting_font(char *map_name, int x, int y)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 50);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, map_name);
    sfText_setPosition(font.text, get_offset(x, y));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

button_t get_settings_button(char *map_name, int x, int y)
{
    button_t setting;

    setting.font = get_setting_font(map_name, x, y);
    return setting;
}

void get_settings_buttons(menu_t *menu)
{
    menu->settings = malloc(sizeof(button_t) * 6);

    menu->settings[0] = get_settings_button("Framerate : 30", 800, 500);
    menu->settings[1] = get_settings_button("Framerate : 60", 800, 500);
    menu->settings[2] = get_settings_button("Framerate : 120", 800, 500);
    menu->settings[3] = get_settings_button("volume", 900, 650);
    menu->settings[4] = get_volume_soundbar();
    menu->settings[5] = get_volume_ext_soundbar();
    return;
}

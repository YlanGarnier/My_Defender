/*
** EPITECH PROJECT, 2022
** wheel.c
** File description:
** map wheel
*/

#include "my_defender.h"
#include "menu.h"
#include <stdlib.h>

void display_maps(window_t *window, menu_t *menu)
{
    for (int i = 0; i != window->map_nb; i++)
        if (menu->map[i].y >= 420 && menu->map[i].y <= 840)
        sfRenderWindow_drawText(window->window, menu->map[i].font.text, NULL);
    return;
}

font_t get_map_font(char *map_name, int y)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 50);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, map_name);
    sfText_setPosition(font.text, get_offset(800, y));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

button_t get_map_button(char *map_name)
{
    button_t map;
    static int y = 420;

    map.font = get_map_font(map_name, y);
    map.y = y;
    y += 75;
    return map;
}

void get_maps_wheel(window_t *window, menu_t *menu)
{
    menu->map = malloc(sizeof(button_t) * window->map_nb);

    for (int i = 0; i != window->map_nb; i++)
        menu->map[i] = get_map_button(window->map_paths[i] += 4);
    return;
}

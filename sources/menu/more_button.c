/*
** EPITECH PROJECT, 2022
** more_button.c
** File description:
** more button
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

int is_mouse_over_help(window_t *window, menu_t *menu)
{
    if ((window->event.mouseButton.x >= 800 &&
    window->event.mouseButton.x <= 950) && (window->event.mouseButton.y >= 800
    && window->event.mouseButton.y <= 900) && menu->test == 1)
        return CLICK;
    else if ((window->event.mouseMove.x >= 800 &&
    window->event.mouseMove.x <= 950) && (window->event.mouseMove.y >= 800
    && window->event.mouseMove.y <= 900))
        return POINT;
    return FALSE;
}

void set_menu_help_button(window_t *window, menu_t *menu)
{
    if (is_mouse_over_help(window, menu) == POINT)
        sfText_setOutlineThickness(menu->help_button[0].font.text, 5);
    else if (is_mouse_over_help(window, menu) == CLICK) {
        menu->state = HELP;
        menu->animation = 1;
    } else
        sfText_setOutlineThickness(menu->help_button[0].font.text, 0);
    return;
}

font_t get_how_to_play_font(void)
{
    font_t font;
    char *str = "Hi and welcome to our my_defender\n2022\
    Epitech project. The goal\nof this game is to protect your castle\nfrom\
    the hordes of enemies coming\nfrom the devil castle. To achieve this\n\
    goal you can place tower on the\nmap, they might do different damages...\n\
    try to click on the grass !";
    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 30);
    sfText_setLineSpacing(font.text, 0.75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, str);
    sfText_setPosition(font.text, get_offset(770, 450));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

font_t get_help_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "More");
    sfText_setPosition(font.text, get_offset(800, 800));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

void get_help_button(menu_t *menu)
{
    menu->help_button[0].font = get_help_font();
    menu->help_button[1].font = get_how_to_play_font();
    return;
}

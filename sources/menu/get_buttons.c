/*
** EPITECH PROJECT, 2022
** buttons.c
** File description:
** buttons
*/

#include "my_defender.h"
#include "menu.h"

sfRectangleShape *get_leader_button()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, get_offset(800, 600));
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    return rect;
}

sfRectangleShape *get_setting_button()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, get_offset(800, 500));
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    return rect;
}

sfRectangleShape *get_quit_button()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, get_offset(800, 700));
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    return rect;
}

sfRectangleShape *get_play_button()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, get_offset(800, 400));
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    return rect;
}

void get_buttons(menu_t *menu)
{
    menu->play_button.font = get_play_font();
    menu->quit_button.font = get_quit_font();
    menu->settings_button.font = get_settings_font();
    menu->leader_button.font = get_leader_font();
    menu->play_button.rect = get_play_button();
    menu->quit_button.rect = get_quit_button();
    menu->settings_button.rect = get_setting_button();
    menu->leader_button.rect = get_leader_button();
    return;
}

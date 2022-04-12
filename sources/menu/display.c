/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

void display_button(window_t *window, sfText *font, sfRectangleShape *rect)
{
    sfRenderWindow_drawText(window->window, font, NULL);
    sfRenderWindow_drawRectangleShape(window->window, rect, NULL);
    return;
}

void display_buttons(window_t *window, menu_t *menu)
{
    display_button
    (window, menu->play_button.font.text, menu->play_button.rect);
    display_button
    (window, menu->quit_button.font.text, menu->quit_button.rect);
    display_button
    (window, menu->settings_button.font.text, menu->settings_button.rect);
    display_button
    (window, menu->leader_button.font.text, menu->leader_button.rect);
    sfRenderWindow_drawText
    (window->window, menu->help_button[0].font.text, NULL);
    return;
}

void display_sprites(window_t *window, menu_t *menu)
{
    if (menu->state != INTRO && menu->animation != 0) {
        sfSound_play(window->sound[2].sound);
        set_scroll_animation(menu);
    }
    sfRenderWindow_drawSprite(window->window, menu->bg.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, menu->board.sprite, NULL);
    sfRenderWindow_drawText(window->window, menu->title.text, NULL);
    if (menu->state != BASE && menu->state != INTRO)
        sfRenderWindow_drawSprite
        (window->window, menu->throwback.sprite, NULL);
    return;
}

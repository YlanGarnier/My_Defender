/*
** EPITECH PROJECT, 2022
** cursor.c
** File description:
** cursor
*/

#include "my_defender.h"
#include "my_macro.h"

void display_cursor(window_t *window)
{
    static int point = 1;
    static int x = 800;
    static int y = 700;

    if (window->event.type == sfEvtMouseButtonPressed) {
        point = CLICK;
        sfSound_play(window->sound[3].sound);
    }
    if (window->event.type == sfEvtMouseButtonReleased)
        point = POINT;
    if (window->event.type == sfEvtMouseMoved) {
        x = window->event.mouseMove.x;
        y = window->event.mouseMove.y;
        sfSprite_setPosition(window->cursor.sprite, (sfVector2f) {x, y});
    }
    if (point == CLICK)
        sfSprite_setTextureRect(window->cursor.sprite, create_rect
        (293, 315, 293, 0));
    else
        sfSprite_setTextureRect(window->cursor.sprite, create_rect
        (293, 315, 0, 0));
    return;
}

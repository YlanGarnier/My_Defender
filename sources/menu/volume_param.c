/*
** EPITECH PROJECT, 2022
** volume_param.c
** File description:
** volume parameters
*/

#include "my_defender.h"
#include "menu.h"

int lower_volume(window_t *window, menu_t *menu, int x)
{
    if (window->event.mouseMove.x <= (x - 6)
    && menu->parameters.volume_rect_x > 0) {
        menu->parameters.volume_rect_x -= 6;
        sfRectangleShape_setSize(menu->settings[4].rect,
        (sfVector2f) {menu->parameters.volume_rect_x, 60});
        menu->parameters.volume_x -= 6;
        sfSprite_setPosition(menu->settings[4].sprite.sprite, (sfVector2f)
    {menu->parameters.volume_x, 738});
        x -= 6;
        if (sfMusic_getVolume(window->sound[0].music) >= 0) {
            sfMusic_setVolume(window->sound[0].music,
            (sfMusic_getVolume(window->sound[0].music) - 6));
            sfMusic_setVolume(window->sound[1].music,
            (sfMusic_getVolume(window->sound[1].music) - 6));
        }
    }
    return x;
}

int up_volume(window_t *window, menu_t *menu, int x)
{
    if (window->event.mouseMove.x >= (x + 6)
    && menu->parameters.volume_rect_x < 320) {
        menu->parameters.volume_rect_x += 6;
        sfRectangleShape_setSize(menu->settings[4].rect,
        (sfVector2f) {menu->parameters.volume_rect_x, 60});
        menu->parameters.volume_x += 6;
        sfSprite_setPosition(menu->settings[4].sprite.sprite, (sfVector2f)
        {menu->parameters.volume_x, 738});
        x += 6;
        if (sfMusic_getVolume(window->sound[0].music) <= 100) {
            sfMusic_setVolume(window->sound[0].music,
            (sfMusic_getVolume(window->sound[0].music) + 6));
            sfMusic_setVolume(window->sound[1].music,
            (sfMusic_getVolume(window->sound[1].music) + 6));
        }
    }
    return x;
}

/*
** EPITECH PROJECT, 2022
** volume_soundbar.c
** File description:
** volume soundbar
*/

#include "my_defender.h"
#include "menu.h"
#include "my_macro.h"

sfSprite *get_volume_sprite()
{
    sfSprite *sprite = create_sprite(sfTexture_createFromFile
    ("assets/menu/volume_button.png", NULL));
    sfSprite_setPosition(sprite, (sfVector2f) {1110, 738});
    sfSprite_setScale(sprite, (sfVector2f) {0.10, 0.12});
    return sprite;
}

sfRectangleShape *get_volume_rect()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f) {810, 750});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(70, 70, 90));
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect, (sfVector2f) {300, 60});
    return rect;
}

sfRectangleShape *get_volume_ext_rect()
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f) {810, 750});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineThickness(rect, 5);
    sfRectangleShape_setSize(rect, (sfVector2f) {300, 60});
    return rect;
}

button_t get_volume_ext_soundbar()
{
    button_t volume;

    volume.rect = get_volume_ext_rect();
    return volume;
}

button_t get_volume_soundbar()
{
    button_t volume;

    volume.rect = get_volume_rect();
    volume.sprite.sprite = get_volume_sprite();
    return volume;
}

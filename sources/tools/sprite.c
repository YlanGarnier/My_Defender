/*
** EPITECH PROJECT, 2022
** drawsprite.c
** File description:
** draw sprites
*/

#include "my_defender.h"
#include <stdlib.h>

void set_pos(sfSprite *sprite, float x, float y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfSprite_setPosition(sprite, pos);
    return;
}

sfVector2f set_scale(float x, float y)
{
    sfVector2f scale;

    scale.x = x;
    scale.y = y;
    return scale;
}

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

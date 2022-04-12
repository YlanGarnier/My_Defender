/*
** EPITECH PROJECT, 2022
** pos.c
** File description:
** position
*/

#include "my_defender.h"

sfIntRect get_rect(int height, int width, int top, int left)
{
    sfIntRect rect;

    rect.height = height;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    return rect;
}

sfVector2f get_offset(float x, float y)
{
    sfVector2f offset;

    offset.x = x;
    offset.y = y;
    return offset;
}

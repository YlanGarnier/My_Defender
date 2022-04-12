/*
** EPITECH PROJECT, 2022
** rect
** File description:
** all functions about rect
*/

#include "my_defender.h"

sfIntRect change_rect(sfIntRect *rect, int left, int left_max, int top)
{
    if (left_max != -1 && rect[0].left >= left_max)
        rect[0].left = 0;
    else if (left_max != -1)
        rect[0].left += left;
    else
        rect[0].left = left;
    if (top != -1)
        rect[0].top = top;
    return rect[0];
}

sfIntRect create_rect(int width, int height, int left, int top)
{
    sfIntRect rect;

    rect.width = width;
    rect.height = height;
    rect.left = left;
    rect.top = top;
    return rect;
}

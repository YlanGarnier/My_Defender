/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** all functions about window
*/

#include <stddef.h>
#include "my_macro.h"
#include "my_defender.h"

sfRenderWindow *create_window(char *title)
{
    sfVideoMode res = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(res, title, sfDefaultStyle,
    NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

window_t set_window(void)
{
    window_t window;

    set_sounds(&window);
    window.map_nb = 0;
    window.score = 0;
    window.state = MENU;
    window.window = create_window("My Defender");
    get_maps(&window);
    window.cursor.sprite = create_sprite(sfTexture_createFromFile
    ("assets/cursor.png", NULL));
    sfSprite_setPosition(window.cursor.sprite, (sfVector2f) {800, 700});
    sfSprite_setTextureRect(window.cursor.sprite, (sfIntRect)
    {315, 293, 0, 293});
    sfRenderWindow_setMouseCursorVisible(window.window, sfFalse);
    sfSprite_setScale(window.cursor.sprite, (sfVector2f) {0.2, 0.2});
    return window;
}

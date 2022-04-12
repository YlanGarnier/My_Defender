/*
** EPITECH PROJECT, 2022
** pause_menu.c
** File description:
** pause menu
*/

#include "my_defender.h"
#include "my_macro.h"

int mouse_click_on_pause(window_t *window, int y)
{
    if ((window->event.mouseButton.x >= 710 &&
    window->event.mouseButton.x <= 1100) && (window->event.mouseButton.y >= y
    && window->event.mouseButton.y <= (y + 100)))
        return TRUE;
    return FALSE;
}
int mouse_is_over_pause(window_t *window, int y)
{
    if ((window->event.mouseMove.x >= 710 &&
    window->event.mouseMove.x <= 1100) && (window->event.mouseMove.y >= y
    && window->event.mouseMove.y <= (y + 100)))
        return TRUE;
    return FALSE;
}

void pause_move_event(window_t *window, game_t *game)
{
    if (mouse_is_over_pause(window, 245) == TRUE)
        game->pause_menu.level = 1;
    if (mouse_is_over_pause(window, 430) == TRUE)
        game->pause_menu.level = 2;
    if (mouse_is_over_pause(window, 615) == TRUE)
        game->pause_menu.level = 3;
    if (mouse_is_over_pause(window, 245) == FALSE
    && mouse_is_over_pause(window, 430) == FALSE
    && mouse_is_over_pause(window, 615) == FALSE)
        game->pause_menu.level = 0;
    return;
}

void pause_click_event(window_t *window, game_t *game)
{
    if (mouse_click_on_pause(window, 245) == TRUE) {
        game->state = GAME;
        sfClock_destroy(game->pause_menu.clock);
    }
    if (mouse_click_on_pause(window, 430) == TRUE) {
        sfMusic_stop(window->sound[1].music);
        window->state = MENU;
        game->stage = 0;
    }
    if (mouse_click_on_pause(window, 615) == TRUE)
        sfRenderWindow_close(window->window);
    return;
}

sfSprite *get_pause_menu()
{
    sfSprite *sprite = create_sprite
    (sfTexture_createFromFile("assets/game/pause_menu.png", NULL));
    sfSprite_setPosition(sprite, (sfVector2f) {655, 130});
    sfSprite_setScale(sprite, (sfVector2f) {4, 4});
    sfSprite_setTextureRect(sprite, create_rect(124, 190, 0, 0));
    return sprite;
}

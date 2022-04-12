/*
** EPITECH PROJECT, 2022
** event
** File description:
** all functions about event
*/

#include "my_macro.h"
#include "my_defender.h"

void esc_events(window_t *window, game_t *game)
{
    if (game->state == GAME) {
        game->state = PAUSE;
        game->pause_menu.clock = sfClock_create();
    } else if (game->state == PAUSE) {
        game->state = GAME;
        sfClock_destroy(game->pause_menu.clock);
    } else {
        game->state = GAME;
        sfSprite_setTextureRect(game->shop.sprite,
        change_rect(&game->shop.rect, 0, -1, -1));
    }
    return;
}

void check_events(window_t *window, game_t *game)
{
    if (window->event.type == sfEvtKeyPressed)
        if (window->event.key.code == 36)
            esc_events(window, game);
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (game->state == SHOP)
            check_selected_tower(window, game);
        if (game->state == GAME)
            check_tower_asking(game, window->event.mouseButton.y,
            window->event.mouseButton.x);
        if (game->state == PAUSE)
            pause_click_event(window, game);
    }
    if (window->event.type == sfEvtMouseMoved) {
        if (game->state == SHOP)
            check_aimed_tower(window, game);
        if (game->state == PAUSE)
            pause_move_event(window, game);
    }
    return;
}

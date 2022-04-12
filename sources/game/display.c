/*
** EPITECH PROJECT, 2022
** display
** File description:
** all functions about display
*/

#include "my_defender.h"
#include "my_macro.h"

void which_menu_state_2(game_t *game)
{
    switch (game->pause_menu.level) {
        case 0:
            game->pause_menu.left = 124;
            break;
        case 1:
            game->pause_menu.left = 372;
            break;
        case 2:
            game->pause_menu.left = 620;
            break;
        case 3:
            game->pause_menu.left = 868;
            break;
    }
    return;
}

void which_menu_state_1(game_t *game)
{
    switch (game->pause_menu.level) {
        case 0:
            game->pause_menu.left = 0;
            break;
        case 1:
            game->pause_menu.left = 248;
            break;
        case 2:
            game->pause_menu.left = 496;
            break;
        case 3:
            game->pause_menu.left = 744;
            break;
    }
    return;
}

void display_pause_menu(window_t *window, game_t *game)
{
    static int a = 0;
    if ((sfClock_getElapsedTime
    (game->pause_menu.clock).microseconds / 100000 >= 3) && a == 0) {
        a = 1;
        which_menu_state_1(game);
        sfClock_restart(game->pause_menu.clock);
    } else if ((sfClock_getElapsedTime
    (game->pause_menu.clock).microseconds / 100000 >= 3) && a == 1) {
        a = 0;
        which_menu_state_2(game);
        sfClock_restart(game->pause_menu.clock);
    }
    sfSprite_setTextureRect(game->pause_menu.sprite,
    create_rect(124, 190, game->pause_menu.left, 0));
    sfRenderWindow_drawSprite
    (window->window, game->pause_menu.sprite, NULL);
    return;
}

void extra_display(window_t *window, game_t *game)
{
    if (game->state == GAME || game->state == SHOP) {
        sfRenderWindow_drawText(window->window, game->money_text.text, NULL);
        sfRenderWindow_drawText(window->window, window->score_text.text, NULL);
    }
    if (game->state == SHOP)
        sfRenderWindow_drawSprite
    (window->window, game->shop.sprite, NULL);
    if (game->is_spawning == 1)
        sfRenderWindow_drawSprite
    (window->window, game->particles.sprite, NULL);
    if (game->state == PAUSE)
        display_pause_menu(window, game);
    sfRenderWindow_drawSprite(window->window, window->cursor.sprite, NULL);
}

void display_game(window_t *window, game_t *game)
{
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    for (int i = 0; i < 144; ++i)
        sfRenderWindow_drawSprite(window->window,
    game->sprite_map[i].sprite, NULL);
    sfRenderWindow_drawText(window->window,
    game->sprite_map[game->castle_pos[2]].text.text, NULL);
    for (int i = 0; i < game->monster_count; ++i) {
        if (game->monster[i].state > 0) {
            sfRenderWindow_drawSprite(window->window,
    game->monster[i].sprite, NULL);
            sfRenderWindow_drawText(window->window,
    game->monster[i].health_text.text, NULL);
        }
    }
    extra_display(window, game);
}

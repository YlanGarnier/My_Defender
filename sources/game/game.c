/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** the game
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_defender.h"

void init_game(window_t *window, game_t *game)
{
    sfMusic_play(window->sound[1].music);
    set_map_textures(window->map[window->which_map], game);
    game->monster_interval.clock = sfClock_create();
    game->state = GAME;
    game->stage = 1;
    game->money = 100;
    set_money(game->money, &game->money_text);
    set_score(window->score, &window->score_text);
    for (int i = 0; i < 20; ++i)
        game->monster[i].state = -1;
    game->shop.sprite = create_sprite(game->texture.shop);
    game->shop.rect = create_rect(242.5, 240, 0, 0);
    game->shop.level = 1;
    sfSprite_setTextureRect(game->shop.sprite, game->shop.rect);
    game->particles.sprite = create_sprite(game->texture.smoke);
    game->particles.rect = create_rect(120, 114, 0, 0);
    sfSprite_setTextureRect(game->particles.sprite, game->particles.rect);
    set_pos(game->particles.sprite, game->spawner_pos[X_COORD] * 120,
game->spawner_pos[Y_COORD] * 114);
    game->pause_menu.sprite = get_pause_menu();
    game->pause_menu.left = 0;
    game->pause_menu.level = 0;
}

void analyse_defender_events(window_t *window, game_t *game)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed) {
            destroy_game_ressources(window, game);
            sfRenderWindow_close(window->window);
        }
        check_events(window, game);
        display_cursor(window);
    }
}

void game_functions(window_t *window, game_t *game)
{
    if (game->stage == 0)
        init_game(window, game);
    analyse_defender_events(window, game);
    if (game->state == GAME || game->state == SHOP) {
        analyse_game_clocks(game);
        monsters_functions(window, game);
    }
    if (game->castle_health <= 0)
        window->state = MENU;
    display_game(window, game);
    return;
}

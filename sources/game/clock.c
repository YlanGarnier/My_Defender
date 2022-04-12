/*
** EPITECH PROJECT, 2022
** clock.c
** File description:
** all functions about clocks
*/

#include <stdlib.h>
#include "my_defender.h"

void set_monster_time(monster_t *monster)
{
    monster->anim_count = sfClock_getElapsedTime
(monster->anim_clock).microseconds / 1000000.0;
    monster->move_count = sfClock_getElapsedTime
(monster->move_clock).microseconds / 1000000.0;
}

void set_game_time(game_t *game)
{
    game->monster_interval.count = sfClock_getElapsedTime
(game->monster_interval.clock).microseconds / 1000000.0;
    if (game->is_spawning == 1)
        game->particles.count = sfClock_getElapsedTime
(game->particles.clock).microseconds / 1000000.0;
}

void analyse_game_clocks(game_t *game)
{
    set_game_time(game);
    if (game->monster_count < 20 && game->monster_interval.count >= 4) {
        ++game->monster_count;
        if (game->stage == 1 && game->monster_count == 10)
            game->stage = 2;
        sfClock_restart(game->monster_interval.clock);
        game->particles.clock = sfClock_create();
    }
    if (game->is_spawning == 1 && game->particles.count >= 0.03) {
        sfSprite_setTextureRect(game->particles.sprite,
change_rect(&game->particles.rect, 120, 1080, -1));
        sfClock_restart(game->particles.clock);
        if (game->particles.rect.left == 0) {
            game->is_spawning = 0;
        }
    }
}

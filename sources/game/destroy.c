/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** all functions about destroy
*/

#include "my_defender.h"

void destroy_monster(game_t *game, monster_t *monster)
{
    if (monster->state == 1)
        game->money += 50;
    if (monster->state == 2) {
        game->money += 125;
        sfClock_destroy(monster->anim_clock);
    }
    refresh_money_text(game->money, &game->money_text);
    sfClock_destroy(monster->move_clock);
    sfSprite_destroy(monster->sprite);
    sfSprite_destroy(monster->particles.sprite);
    monster->state = 0;
}

void destroy_game_sounds(window_t *window, game_t *game)
{
    sfMusic_destroy(window->sound[0].music);
    sfMusic_destroy(window->sound[1].music);
}

void destroy_game_ressources(window_t *window, game_t *game)
{
    destroy_game_sounds(window, game);
}

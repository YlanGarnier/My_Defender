/*
** EPITECH PROJECT, 2022
** monster
** File description:
** all functions about monsters
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

void check_killed_monster(window_t *window, monster_t *monster)
{
    if (monster->health <= 0) {
        monster->state = 0;
        window->score += 10;
        refresh_score_text(window->score, &window->score_text);
        reset_tower(window, monster);
    }
}

void move_monster(monster_t *monster)
{
    if (monster->direction != -1)
        refresh_health_bar_pos(monster);
    if (monster->direction == UP && monster->move_count >= 0.01) {
        sfSprite_move(monster->sprite, get_offset(0, -2));
        sfClock_restart(monster->move_clock);
    }
    if (monster->direction == DOWN && monster->move_count >= 0.01) {
        sfSprite_move(monster->sprite, get_offset(0, 2));
        sfClock_restart(monster->move_clock);
    }
    if (monster->direction == LEFT && monster->move_count >= 0.01) {
        sfSprite_move(monster->sprite, get_offset(-2, 0));
        sfClock_restart(monster->move_clock);
    }
    if (monster->direction == RIGHT && monster->move_count >= 0.01) {
        sfSprite_move(monster->sprite, get_offset(2, 0));
        sfClock_restart(monster->move_clock);
    }
}

void check_monster(window_t *window, game_t *game, monster_t *monster)
{
    int co[2];
    co[0] = sfSprite_getPosition(monster->sprite).y - monster->coord[Y_OFF];
    co[1] = sfSprite_getPosition(monster->sprite).x - monster->coord[X_OFF];
    set_monster_time(monster);
    check_killed_monster(window, monster);
    if (monster->state == 1 && monster->anim_count >= 0.1) {
        if (monster->stage == 1)
            sfSprite_setTextureRect(monster->sprite,
            change_rect(&monster->rect, 59, 295, -1));
        else
            sfSprite_setTextureRect(monster->sprite,
            change_rect(&monster->rect, 71, 497, -1));
        sfClock_restart(monster->anim_clock);
    }
    if (monster->state == 1 && co[0] % 114 == 0 && co[1] % 120 == 0)
        check_pos_monster(window, game, monster, co);
    move_monster(monster);
}

void monster_attack(game_t *game, monster_t *monster)
{
    monster->move_count = sfClock_getElapsedTime
(monster->move_clock).microseconds / 1000000.0;
    if (monster->state == 2) {
        game->castle_health -= monster->damage;
        sfText_setString(game->sprite_map[game->castle_pos[MAP_INDEX]]
.text.text, my_strcat(my_getstr(game->castle_health), "/1000"));
        sfClock_restart(monster->move_clock);
        sfClock_destroy(monster->anim_clock);
        ++monster->state;
    }
    if (monster->state == 3 && monster->move_count >= 1) {
        game->castle_health -= monster->damage;
        sfText_setString(game->sprite_map[game->castle_pos[MAP_INDEX]]
.text.text, my_strcat(my_getstr(game->castle_health), "/1000"));
        sfClock_restart(monster->move_clock);
    }
}

void monsters_functions(window_t *window, game_t *game)
{
    for (int i = 0; i < game->monster_count; ++i) {
        if (game->monster[i].state == -1)
            init_monster(game, i);
        else if (game->monster[i].state == 1)
            check_monster(window, game, &game->monster[i]);
        if (game->monster[i].state > 1)
            monster_attack(game, &game->monster[i]);
    }
}

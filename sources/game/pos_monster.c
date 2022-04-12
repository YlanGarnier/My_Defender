/*
** EPITECH PROJECT, 2022
** pos_monster
** File description:
** all functions about pos monster
*/

#include "my_macro.h"
#include "my_defender.h"

void reset_tower(window_t *window, monster_t *monster)
{
    if (monster->tower_pos[Y_COORD] != -1) {
        window->map[window->which_map][monster->tower_pos[Y_COORD]]
[monster->tower_pos[X_COORD]] = monster->tower_pos[2] + 48;
        monster->tower_pos[Y_COORD] = -1;
    }
}

void check_pos_monster(window_t *window, game_t *game,
monster_t *monster, int coord[2])
{
    monster->direction = find_next_pos
(window->map[window->which_map], monster, 'D');
    if (monster->direction == -1)
        monster->state = 2;
    tower_attack(window->map[window->which_map], monster, coord);
    if (monster->tower_pos[Y_COORD] != -1) {
        reduce_damage(monster, monster->tower_pos[2],
monster->tower_pos[Y_COORD], monster->tower_pos[X_COORD]);
        window->map[window->which_map][monster->tower_pos[Y_COORD]]
[monster->tower_pos[X_COORD]] = '0';
        if (not_anymore_attacked(monster) == 1)
            reset_tower(window, monster);
        else
            refresh_money_text(game->money += 10, &game->money_text);
    }
}

int check_up_down_pos(char **map, monster_t *monster, char c)
{
    if (monster->direction != DOWN && monster->coord[Y_COORD]
> 0 && map[monster->coord[Y_COORD] - 1][monster->coord[X_COORD]] == c) {
        --monster->coord[Y_COORD];
        sfSprite_setTextureRect(monster->sprite,
change_rect(&monster->rect, 0, -1, monster->top * 0));
        return UP;
    }
    if (monster->direction != UP && monster->coord[Y_COORD] < 8
&& map[monster->coord[Y_COORD] + 1][monster->coord[X_COORD]] == c) {
        ++monster->coord[Y_COORD];
        sfSprite_setTextureRect(monster->sprite,
change_rect(&monster->rect, 0, -1, monster->top * 1));
        return DOWN;
    }
    return -1;
}

int find_next_pos(char **map, monster_t *monster, char c)
{
    int ret = check_up_down_pos(map, monster, c);

    if (ret != -1)
        return ret;
    if (monster->direction != LEFT && monster->coord[X_COORD]
< 15 && map[monster->coord[Y_COORD]][monster->coord[X_COORD] + 1] == c) {
        ++monster->coord[X_COORD];
        sfSprite_setTextureRect(monster->sprite,
change_rect(&monster->rect, 0, -1, monster->top * 2));
        return RIGHT;
    }
    if (monster->direction != RIGHT && monster->coord[X_COORD]
> 0 && map[monster->coord[Y_COORD]][monster->coord[X_COORD] - 1] == c) {
        --monster->coord[X_COORD];
        sfSprite_setTextureRect(monster->sprite,
change_rect(&monster->rect, 0, -1, monster->top * 3));
        return LEFT;
    }
    return -1;
}

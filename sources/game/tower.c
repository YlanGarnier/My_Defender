/*
** EPITECH PROJECT, 2022
** tower
** File description:
** all functions about tower
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

int tower_attack_diagonal(char **map, monster_t *monster, int y, int x)
{
    if (y < 8 && map[y + 1][x] >= '1' && map[y + 1][x] <= '4')
        return reduce_damage(monster, map[y + 1][x] - 48, y + 1, x);
    if (x > 0 && y > 0 && map[y - 1][x - 1] >= 49 && map[y - 1][x - 1] <= 52)
        return reduce_damage(monster, map[y - 1][x - 1] - 48, y - 1, x - 1);
    if (x < 15 && y < 8 && map[y + 1][x + 1] >= 49 && map[y + 1][x + 1] <= 52)
        return reduce_damage(monster, map[y + 1][x + 1] - 48, y + 1, x + 1);
    if (y > 0 && x < 15 && map[y - 1][x + 1] >= 49 && map[y - 1][x + 1] <= 52)
        return reduce_damage(monster, map[y - 1][x + 1] - 48, y - 1, x + 1);
    if (y < 8 && x > 0 && map[y + 1][x - 1] >= 49 && map[y + 1][x - 1] <= 52)
        return reduce_damage(monster, map[y + 1][x - 1] - 48, y + 1, x - 1);
    return 0;
}

void tower_attack(char **map, monster_t *monster, int coord[2])
{
    int ret = 0;
    int y = coord[Y_COORD] / 114;
    int x = coord[X_COORD] / 120;
    if (x > 0 && map[y][x - 1] >= '1' && map[y][x - 1] <= '4')
        ret = reduce_damage(monster, map[y][x - 1] - 48, y, x - 1);
    if (x < 15 && map[y][x + 1] >= '1' && map[y][x + 1] <= '4')
        ret = reduce_damage(monster, map[y][x + 1] - 48, y, x + 1);
    if (y > 0 && map[y - 1][x] >= '1' && map[y - 1][x] <= '4')
        ret = reduce_damage(monster, map[y - 1][x] - 48, y - 1, x);
    if (ret == 0)
        ret = tower_attack_diagonal(map, monster, y, x);
}

void place_tower(window_t *window, game_t *game, int y, int x)
{
    game->sprite_map[game->tower_pos[MAP_INDEX]].type
= game->tower_pos[TYPE] + 48;
    window->map[window->which_map][y][x] = game->tower_pos[TYPE] + 48;
    if (game->tower_pos[TYPE] == 1)
        sfSprite_setTexture(game->sprite_map[
game->tower_pos[MAP_INDEX]].sprite, game->texture.tower1, sfFalse);
    if (game->tower_pos[TYPE] == 2)
        sfSprite_setTexture(game->sprite_map[
game->tower_pos[MAP_INDEX]].sprite, game->texture.tower2, sfFalse);
    if (game->tower_pos[TYPE] == 3)
        sfSprite_setTexture(game->sprite_map[
game->tower_pos[MAP_INDEX]].sprite, game->texture.tower3, sfFalse);
    if (game->tower_pos[TYPE] == 4)
        sfSprite_setTexture(game->sprite_map[
game->tower_pos[MAP_INDEX]].sprite, game->texture.tower4, sfFalse);
    game->money -= game->tower_pos[TYPE] * 100;
    refresh_money_text(game->money, &game->money_text);
}

void check_case(game_t *game, int i, int coords[4])
{
    if (game->sprite_map[i].type == ' ') {
        game->state = SHOP;
        sfSprite_setPosition(game->shop.sprite,
get_offset(coords[3] - 42, coords[2] - 42));
        game->tower_pos[Y_COORD] = coords[0] / 114;
        game->tower_pos[X_COORD] = coords[1] / 120;
        game->tower_pos[MAP_INDEX] = i;
    } else
        game->state = GAME;
}

void check_tower_asking(game_t *game, int cursor_y, int cursor_x)
{
    int coords[4];

    for (int i = 0; i < 144; ++i) {
        coords[0] = sfSprite_getPosition(game->sprite_map[i].sprite).y;
        coords[1] = sfSprite_getPosition(game->sprite_map[i].sprite).x;
        coords[2] = cursor_y;
        coords[3] = cursor_x;
        if (cursor_y >= coords[0] && cursor_y <= coords[0] + 114
&& cursor_x >= coords[1] && cursor_x <= coords[1] + 120)
            check_case(game, i, coords);
    }
}

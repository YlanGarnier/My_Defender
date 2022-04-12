/*
** EPITECH PROJECT, 2022
** tower_attacks
** File description:
** all functions about tower_attacks
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

int not_anymore_attacked_diagonal(monster_t *monster, int x, int y)
{
    if ((x > 0 && y > 0) && (x - 1 == monster->tower_pos[X_COORD]
&& y - 1 == monster->tower_pos[Y_COORD]))
        return 0;
    if ((x < 15 && y < 8) && (x + 1 == monster->tower_pos[X_COORD]
&& y + 1 == monster->tower_pos[Y_COORD]))
        return 0;
    if ((y > 0 && x < 15) && (x + 1 == monster->tower_pos[X_COORD]
&& y - 1 == monster->tower_pos[Y_COORD]))
        return 0;
    if ((y < 8 && x > 0) && (x - 1 == monster->tower_pos[X_COORD]
&& y + 1 == monster->tower_pos[Y_COORD]))
        return 0;
    return 1;
}

int not_anymore_attacked(monster_t *monster)
{
    int x = monster->coord[X_COORD];
    int y = monster->coord[Y_COORD];

    if (x > 0 && (x - 1 == monster->tower_pos[X_COORD] &&
y == monster->tower_pos[Y_COORD]))
        return 0;
    if (x < 15 && (x + 1 == monster->tower_pos[X_COORD] &&
y == monster->tower_pos[Y_COORD]))
        return 0;
    if (y > 0 && (y - 1 == monster->tower_pos[Y_COORD]
&& x == monster->tower_pos[X_COORD]))
        return 0;
    if (y < 8 && (y + 1 == monster->tower_pos[Y_COORD]
&& x == monster->tower_pos[X_COORD]))
        return 0;
    return not_anymore_attacked_diagonal(monster, x, y);
}

int reduce_damage(monster_t *monster, int level, int y, int x)
{
    if (level == 1)
        monster->health -= 5;
    if (level == 2)
        monster->health -= 10;
    if (level == 3)
        monster->health -= 15;
    if (level == 4)
        monster->health -= 25;
    sfText_setString(monster->health_text.text,
    my_strcat(my_getstr(monster->health), "/100"));
    monster->tower_pos[Y_COORD] = y;
    monster->tower_pos[X_COORD] = x;
    monster->tower_pos[2] = level;
    return 1;
}

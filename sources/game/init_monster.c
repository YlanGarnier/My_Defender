/*
** EPITECH PROJECT, 2022
** init_monster
** File description:
** all fonctions about initing monsters
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

void init_health_bar(monster_t *monster)
{
    monster->health_text.font = sfFont_createFromFile("fonts/menu.ttf");
    monster->health_text.text = sfText_create();
    if (monster->stage == 1) {
        monster->health_text.y_offset = -20;
        monster->health_text.x_offset = -5;
    } else {
        monster->health_text.y_offset = 0;
        monster->health_text.x_offset = 0;
    }
    sfText_setFont(monster->health_text.text, monster->health_text.font);
    sfText_setCharacterSize(monster->health_text.text, 18);
    if (monster->stage == 1)
        sfText_setString(monster->health_text.text,
my_strcat(my_getstr(monster->health), "/100"));
    if (monster->stage == 2)
        sfText_setString(monster->health_text.text,
my_strcat(my_getstr(monster->health), "/500"));
    sfText_setFillColor(monster->health_text.text, sfRed);
    refresh_health_bar_pos(monster);
    sfText_setOutlineThickness(monster->health_text.text, 1);
}

void init_minotaur(game_t *game, int i)
{
    game->monster[i].sprite = create_sprite(game->texture.minotaur);
    game->monster[i].rect = create_rect(71, 120, 0, 0);
    sfSprite_setTextureRect(game->monster[i].sprite, game->monster[i].rect);
    game->monster[i].stage = 2;
    game->monster[i].coord[Y_OFF] = -5;
    game->monster[i].coord[X_OFF] = 25;
    game->monster[i].top = 120;
    set_pos(game->monster[i].sprite, game->spawner_pos[X_COORD] +
game->monster[i].coord[X_OFF], game->spawner_pos[Y_COORD] +
game->monster[i].coord[Y_OFF]);
    game->monster[i].health_max = 500;
    game->monster[i].health = game->monster[i].health_max;
    game->monster[i].damage = 100;
}

void init_dino(game_t *game, int i)
{
    game->monster[i].sprite = create_sprite(game->texture.goblin);
    game->monster[i].rect = create_rect(59, 60, 0, 0);
    sfSprite_setTextureRect(game->monster[i].sprite, game->monster[i].rect);
    game->monster[i].stage = 1;
    game->monster[i].coord[Y_OFF] = 25;
    game->monster[i].coord[X_OFF] = 29;
    game->monster[i].top = 60;
    set_pos(game->monster[i].sprite, (game->spawner_pos[X_COORD] * 120) +
game->monster[i].coord[X_OFF], (game->spawner_pos[Y_COORD] * 114)
+ game->monster[i].coord[Y_OFF]);
    game->monster[i].health_max = 100;
    game->monster[i].health = game->monster[i].health_max;
    game->monster[i].damage = 25;
}

void init_monster(game_t *game, int i)
{
    game->monster[i].state = 1;
    game->monster[i].coord[Y_COORD] = game->spawner_pos[Y_COORD];
    game->monster[i].coord[X_COORD] = game->spawner_pos[X_COORD];
    game->monster[i].tower_pos[Y_COORD] = -1;
    game->monster[i].direction = -1;
    game->is_spawning = 1;
    game->particles.clock = sfClock_create();
    game->monster[i].anim_clock = sfClock_create();
    game->monster[i].move_clock = sfClock_create();
    if (game->stage == 1)
        init_dino(game, i);
    if (game->stage == 2)
        init_minotaur(game, i);
    init_health_bar(&game->monster[i]);
}

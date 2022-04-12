/*
** EPITECH PROJECT, 2022
** game
** File description:
** all functions about setting game
*/

#include "my_defender.h"

void set_tower_textures(game_t *game)
{
    game->texture.tower1 = sfTexture_createFromFile
("assets/game/tower1.png", NULL);
    game->texture.tower2 = sfTexture_createFromFile
("assets/game/tower2.png", NULL);
    game->texture.tower3 = sfTexture_createFromFile
("assets/game/tower3.png", NULL);
    game->texture.tower4 = sfTexture_createFromFile
("assets/game/tower4.png", NULL);
}

void set_game_textures(game_t *game)
{
    game->texture.shop = sfTexture_createFromFile
("assets/game/shop.png", NULL);
    game->texture.smoke = sfTexture_createFromFile
("assets/game/smoke.png", NULL);
    game->texture.spawner = sfTexture_createFromFile
("assets/game/spawner.png", NULL);
    game->texture.dirt = sfTexture_createFromFile
("assets/game/dirt.png", NULL);
    game->texture.grass = sfTexture_createFromFile
("assets/game/grass.png", NULL);
    game->texture.tree = sfTexture_createFromFile
("assets/game/tree.png", NULL);
    game->texture.castle = sfTexture_createFromFile
("assets/game/castle.png", NULL);
    game->texture.goblin = sfTexture_createFromFile
("assets/game/dino.png", NULL);
    game->texture.minotaur = sfTexture_createFromFile
("assets/game/minotaur.png", NULL);
    set_tower_textures(game);
}

game_t set_game(void)
{
    game_t game;

    game.stage = 0;
    game.monster_count = 0;
    game.is_spawning = 0;
    game.castle_health = 1000;
    set_game_textures(&game);
    return game;
}

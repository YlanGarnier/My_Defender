/*
** EPITECH PROJECT, 2022
** textures
** File description:
** all functions about textures
*/

#include "my_macro.h"
#include "my.h"
#include "my_defender.h"

int set_castle_structure(sprite_t *texture, game_t *game, int map_pos[3])
{
    texture->sprite = create_sprite(game->texture.castle);
    game->castle_pos[Y_COORD] = map_pos[Y_COORD] / 114;
    game->castle_pos[X_COORD] = map_pos[X_COORD] / 120;
    texture->sprite = create_sprite(game->texture.castle);
    game->castle_pos[Y_COORD] = map_pos[Y_COORD] / 114;
    game->castle_pos[X_COORD] = map_pos[X_COORD] / 120;
    texture->text.font = sfFont_createFromFile("fonts/menu.ttf");
    texture->text.text = sfText_create();
    sfText_setFont(texture->text.text, texture->text.font);
    sfText_setCharacterSize(texture->text.text, 20);
    sfText_setString(texture->text.text,
my_strcat(my_getstr(game->castle_health), "/1000"));
    sfText_setFillColor(texture->text.text, sfGreen);
    sfText_setPosition(texture->text.text,
get_offset(map_pos[X_COORD] + 8, map_pos[Y_COORD] + 2));
    sfText_setOutlineThickness(texture->text.text, 1);
    game->castle_pos[2] = map_pos[2];
    return 1;
}

int analyse_textures(char c, sprite_t *texture, game_t *game,
int map_pos[3])
{
    if (c == 'S') {
        texture->sprite = create_sprite(game->texture.spawner);
        game->spawner_pos[Y_COORD] = map_pos[Y_COORD] / 114;
        game->spawner_pos[X_COORD] = map_pos[X_COORD] / 120;
    }
    if (c == 'D')
        texture->sprite = create_sprite(game->texture.dirt);
    if (c == ' ')
        texture->sprite = create_sprite(game->texture.grass);
    if (c == 'T')
        texture->sprite = create_sprite(game->texture.tree);
    if (c == 'C')
        return set_castle_structure(texture, game, map_pos);
    return 0;
}

void set_map_textures(char **map, game_t *game)
{
    int map_pos[3];

    map_pos[2] = 0;
    map_pos[Y_COORD] = 0;
    for (int l = 0; l < 9; ++l, map_pos[Y_COORD] += 114) {
        map_pos[X_COORD] = 0;
        for (int c = 0; c < 16; ++c, map_pos[X_COORD] += 120) {
            analyse_textures(map[l][c],
&game->sprite_map[map_pos[2]], game, map_pos);
            game->sprite_map[map_pos[2]].type = map[l][c];
            set_pos(game->sprite_map[map_pos[2]].sprite,
map_pos[X_COORD], map_pos[Y_COORD]);
            ++map_pos[2];
        }
    }
    return;
}

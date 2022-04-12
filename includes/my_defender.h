/*
** EPITECH PROJECT, 2022
** my_defender.h
** File description:
** my_defender tools
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Cursor.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <stdio.h>

#ifndef MY_DEFENDER_H_
    #define MY_DEFENDER_H_

typedef struct sound_s {
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct font_s {
    sfFont *font;
    sfText *text;
    int y_offset;
    int x_offset;
} font_t;

typedef struct sprite_s {
    char type;
    sfSprite *sprite;
    sfClock *clock;
    font_t text;
    int level;
    float count;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int left;
} sprite_t;

typedef struct clocks_s {
    sfClock *clock;
    sfTime time;
    float count;
} clocks_t;

typedef struct window_s {
    sfEvent event;
    sfRenderWindow *window;
    int state;
    int map_nb;
    int which_map;
    char **map_paths;
    char ***map;
    sfVector2f mouse;
    sprite_t cursor;
    sound_t sound[4];
    int score;
    font_t score_text;
} window_t;

typedef struct button_s {
    font_t font;
    sfRectangleShape *rect;
    sprite_t sprite;
    int y;
} button_t;

typedef struct monster_s {
    int state;
    int stage;
    int health_max;
    int health;
    int damage;
    int coord[4];
    int tower_pos[3];
    int top;
    int direction;
    font_t health_text;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *anim_clock;
    float anim_count;
    sfClock *move_clock;
    float move_count;
    sprite_t particles;
} monster_t;

typedef struct texture_s {
    sfTexture *shop;
    sfTexture *smoke;
    sfTexture *spawner;
    sfTexture *dirt;
    sfTexture *grass;
    sfTexture *tree;
    sfTexture *castle;
    sfTexture *goblin;
    sfTexture *minotaur;
    sfTexture *tower1;
    sfTexture *tower2;
    sfTexture *tower3;
    sfTexture *tower4;
} texture_t;

typedef struct game_s {
    int state;
    int stage;
    int money;
    int castle_health;
    int tower_pos[3];
    int castle_pos[3];
    int spawner_pos[2];
    texture_t texture;
    int is_spawning;
    font_t money_text;
    sprite_t sprite_map[144];
    sprite_t shop;
    sprite_t particles;
    clocks_t monster_interval;
    monster_t monster[20];
    int monster_count;
    sprite_t pause_menu;
} game_t;

// tower_attacks.c
int not_anymore_attacked(monster_t *monster);
int reduce_damage(monster_t *monster, int level, int y, int x);
// destroy.c
void destroy_monster(game_t *game, monster_t *monster);
void destroy_game_ressources(window_t *window, game_t *game);
// pause_menu.c
void pause_move_event(window_t *window, game_t *game);
void pause_click_event(window_t *window, game_t *game);
sfSprite *get_pause_menu();
// cursor.c
void display_cursor(window_t *window);
// sounds.c
void set_sounds(window_t *window);
// textures.c
int analyse_textures(char c, sprite_t *texture, game_t *game,
int map_pos[3]);
int set_castle_structure(sprite_t *texture, game_t *game, int map_pos[3]);
void set_map_textures(char **map, game_t *game);
// shop.c
int check_aimed_tower(window_t *window, game_t *game);
void check_selected_tower(window_t *window, game_t *game);
// event.c
void check_events(window_t *window, game_t *game);
// set_game.c
void set_game_textures(game_t *game);
game_t set_game(void);
// display.c
void display_game(window_t *window, game_t *game);
// tower.c
void tower_attack(char **map, monster_t *monster, int coord[2]);
void place_tower(window_t *window, game_t *game, int y, int x);
void check_tower_asking(game_t *game, int cursor_y, int cursor_x);
// text.c
void refresh_money_text(int money, font_t *money_text);
void set_money(int money, font_t *money_text);
void refresh_health_bar_pos(monster_t *monster);
void set_score(int score, font_t *score_text);
void refresh_money_text(int score, font_t *score_text);
void refresh_score_text(int score, font_t *score_text);
// rect.c
sfIntRect change_rect(sfIntRect *rect, int left, int left_max, int top);
sfIntRect create_rect(int width, int height, int left, int top);
// monster.c
int not_anymore_attacked(monster_t *monster);
void monsters_functions(window_t *window, game_t *game);
// pos_monster.c
void reset_tower(window_t *window, monster_t *monster);
void check_pos_monster(window_t *window, game_t *game,
monster_t *monster, int coord[2]);
int find_next_pos(char **map, monster_t *monster, char c);
// init_monster.c
void init_monster(game_t *game, int i);
// clock.c
void set_monster_time(monster_t *monster);
void analyse_game_clocks(game_t *game);
// map.c
void set_map_textures(char **map, game_t *game);
char **set_map(char *path);
void get_maps(window_t *window);
// sprite.c
void set_pos(sfSprite *sprite, float x, float y);
sfVector2f set_scale(float x, float y);
sfSprite *create_sprite(sfTexture *texture);
// pos.c
sfVector2f get_offset(float x, float y);
sfIntRect get_rect(int height, int width, int top, int left);
// game.c
void game_functions(window_t *window, game_t *game);
// defender.c
int defender(void);
// window.c
window_t set_window(void);
// usage.c
int usage(void);
// error_handling.c
int error_handling(int ac);

#endif

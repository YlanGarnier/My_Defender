/*
** EPITECH PROJECT, 2022
** menu.h
** File description:
** menu tools
*/

#include "my_defender.h"

#ifndef MENUTOOLS_H_
    #define MENUTOOLS_H_

typedef struct menu_settings_s {
    int framerate;
    int volume_x;
    int volume_rect_x;
    int release;
} menu_settings_t;

typedef struct menu_s {
    int state;
    int animation;
    sprite_t bg;
    sprite_t board;
    sprite_t throwback;
    font_t title;
    button_t play_button;
    button_t quit_button;
    button_t settings_button;
    button_t leader_button;
    button_t help_button[2];
    button_t *map;
    button_t *settings;
    button_t *more;
    clocks_t clock;
    int test;
    menu_settings_t parameters;
} menu_t;

// more_button.c
void get_help_button(menu_t *menu);
void set_menu_help_button(window_t *window, menu_t *menu);
// volume_param.c
int up_volume(window_t *window, menu_t *menu, int x);
int lower_volume(window_t *window, menu_t *menu, int x);
// set_volume_soundbar.c
button_t get_volume_soundbar();
button_t get_volume_ext_soundbar();
// set_settings_buttons.c
void set_settings_buttons(window_t *window, menu_t *menu);
void set_volume_soundbar(window_t *window, menu_t *menu);
// settings_button.c
void get_settings_buttons(menu_t *menu);
void display_settings(window_t *window, menu_t *menu);
// throwback_button.c
void set_throwback_button(window_t *window, menu_t *menu);
// intro.c
void intro(window_t *window, menu_t *menu);
// scroll_animation.c
void set_scroll_animation(menu_t *menu);
// wheel_param.c
void set_map_selection(window_t *window, menu_t *menu);
// display_wheel.c
void set_wheel(window_t *window, menu_t *menu);
// wheel.c
void display_maps(window_t *window, menu_t *menu);
void get_maps_wheel(window_t *window, menu_t *menu);
// buttons_param.c
int is_mouse_over_play(window_t *window, menu_t *menu);
int is_mouse_over_quit(window_t *window, menu_t *menu);
int is_mouse_over_leader(window_t *window, menu_t *menu);
int is_mouse_over_settings(window_t *window, menu_t *menu);
// event.c
void check_event(window_t *window, menu_t *menu);
// set_buttons.c
void set_menu_buttons(window_t *window, menu_t *menu);
// display.c
void display_button(window_t *window, sfText *font, sfRectangleShape *rect);
void display_buttons(window_t *window, menu_t *menu);
void display_sprites(window_t *window, menu_t *menu);
// get_buttons.c
void get_buttons(menu_t *menu);
// sprites.c
void set_menu_sprites(window_t *window, menu_t *menu);
void get_sprites(menu_t *menu);
void get_board(menu_t *menu);
// menu.c
void menu_functions(window_t *window, menu_t *menu);
menu_t set_menu(window_t *window);
// fonts.c
font_t get_title_font(void);
font_t get_play_font(void);
font_t get_quit_font(void);
font_t get_leader_font(void);
font_t get_settings_font(void);

#endif /* !MENUTOOLS_H_ */

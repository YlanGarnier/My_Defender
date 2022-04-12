/*
** EPITECH PROJECT, 2022
** board.c
** File description:
** board of the menu
*/

#include "my_defender.h"
#include "menu.h"

void set_menu_sprites(window_t *window, menu_t *menu)
{
    set_throwback_button(window, menu);
    return;
}

void get_throwback_button(menu_t *menu)
{
    sfSprite_setTextureRect(menu->throwback.sprite, get_rect(512, 512, 0, 0));
    sfSprite_setPosition(menu->throwback.sprite, get_offset(1065, 370));
    sfSprite_setScale(menu->throwback.sprite, set_scale(0.1, 0.1));
    return;
}

void get_board(menu_t *menu)
{
    sfSprite_setPosition(menu->board.sprite, get_offset(645, 300));
    sfSprite_setScale(menu->board.sprite, set_scale(2.5, 2.5));
    sfSprite_setTextureRect(menu->board.sprite, get_rect(285, 253, 0, 0));
    return;
}

void get_sprites(menu_t *menu)
{
    menu->bg.sprite = create_sprite(sfTexture_createFromFile
    ("assets/menu/menu_background.png", NULL));
    menu->board.sprite = create_sprite(sfTexture_createFromFile
    ("assets/menu/scroll.png", NULL));
    menu->throwback.sprite = create_sprite(sfTexture_createFromFile
    ("assets/menu/back_arrow.png", NULL));
    get_board(menu);
    get_throwback_button(menu);
    menu->title = get_title_font();
    return;
}

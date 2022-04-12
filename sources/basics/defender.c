/*
** EPITECH PROJECT, 2022
** defender.c
** File description:
** my defender
*/

#include "my_macro.h"
#include "my_defender.h"
#include "menu.h"

int defender(void)
{
    window_t window = set_window();
    menu_t menu = set_menu(&window);
    game_t game = set_game();

    while (sfRenderWindow_isOpen(window.window)) {
        if (window.state == MENU)
            menu_functions(&window, &menu);
        else if (window.state == GAME)
            game_functions(&window, &game);
    }
    return 0;
}

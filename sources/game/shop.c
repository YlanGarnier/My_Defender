/*
** EPITECH PROJECT, 2022
** pause
** File description:
** all functions about pause
*/

#include "my_macro.h"
#include "my_defender.h"

void check_third_four_towers(window_t *window, game_t *game,
int y_shop)
{
    if (game->tower_pos[TYPE] == -1 && game->money >= 400 &&
window->event.mouseButton.y >= y_shop + 174 &&
window->event.mouseButton.y <= y_shop + 242)
        game->tower_pos[TYPE] = 4;
    if (game->tower_pos[TYPE] != -1) {
        place_tower(window, game, game->tower_pos[Y_COORD],
game->tower_pos[X_COORD]);
        game->state = GAME;
    }
}

void check_selected_tower(window_t *window, game_t *game)
{
    int y_shop = sfSprite_getPosition(game->shop.sprite).y;
    game->tower_pos[TYPE] = -1;
    if (game->tower_pos[TYPE] == -1 && game->money >= 100 &&
window->event.mouseButton.y >= y_shop && window->event.mouseButton.y
<= y_shop + 67)
        game->tower_pos[TYPE] = 1;
    if (game->tower_pos[TYPE] == -1 && game->money >= 200 &&
window->event.mouseButton.y >= y_shop + 68 &&
window->event.mouseButton.y <= y_shop + 120)
        game->tower_pos[TYPE] = 2;
    if (game->tower_pos[TYPE] == -1 && game->money >= 300
&& window->event.mouseButton.y
>= y_shop + 121 && window->event.mouseButton.y <= y_shop + 173)
        game->tower_pos[TYPE] = 3;
    check_third_four_towers(window, game, y_shop);
}

int update_shop(game_t *game, int tower, int left)
{
    game->shop.level = tower;
    sfSprite_setTextureRect(game->shop.sprite,
change_rect(&game->shop.rect, left, -1, -1));
    return 1;
}

int check_aimed_tower(window_t *w, game_t *g)
{
    int x = sfSprite_getPosition(g->shop.sprite).x;
    int y = sfSprite_getPosition(g->shop.sprite).y;
    if (!(w->event.mouseMove.x >= x && w->event.mouseMove.x <= x
+ 242 && w->event.mouseMove.y >= y && w->event.mouseMove.y <= y + 240)) {
        g->state = GAME;
        sfSprite_setTextureRect(g->shop.sprite,
change_rect(&g->shop.rect, 0, -1, -1));
    }
    if (w->event.mouseMove.y >= y && w->event.mouseMove.y <= y + 67)
        return update_shop(g, 1, 0);
    if (w->event.mouseMove.y >= y + 68 && w->event.mouseMove.y <= y + 120)
        return update_shop(g, 2, 242);
    if (w->event.mouseMove.y >= y + 121 && w->event.mouseMove.y <= y + 173)
        return update_shop(g, 3, 485);
    if (w->event.mouseMove.y >= y + 174 && w->event.mouseMove.y <= y + 242)
        return update_shop(g, 4, 727);
    return 0;
}

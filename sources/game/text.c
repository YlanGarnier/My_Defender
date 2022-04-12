/*
** EPITECH PROJECT, 2022
** text
** File description:
** all functions about text
*/

#include "my.h"
#include "my_defender.h"

void refresh_health_bar_pos(monster_t *monster)
{
    sfText_setPosition(monster->health_text.text, get_offset(
sfSprite_getPosition(monster->sprite).x + monster->health_text.x_offset,
sfSprite_getPosition(monster->sprite).y
+ monster->health_text.y_offset));
}

void refresh_money_text(int money, font_t *money_text)
{
    sfText_setString(money_text->text,
my_strcat(my_getstr(money), "$"));
}

void refresh_score_text(int score, font_t *score_text)
{
    sfText_setString(score_text->text,
    my_getstr(score));
}

void set_score(int score, font_t *score_text)
{
    score_text->font = sfFont_createFromFile("fonts/menu.ttf");
    score_text->text = sfText_create();
    sfText_setFont(score_text->text, score_text->font);
    sfText_setCharacterSize(score_text->text, 40);
    sfText_setString(score_text->text,
    my_getstr(score));
    sfText_setFillColor(score_text->text, sfBlue);
    sfText_setOutlineThickness(score_text->text, 1);
    sfText_setPosition(score_text->text, get_offset(1200, 10));
}

void set_money(int money, font_t *money_text)
{
    money_text->font = sfFont_createFromFile("fonts/menu.ttf");
    money_text->text = sfText_create();
    sfText_setFont(money_text->text, money_text->font);
    sfText_setCharacterSize(money_text->text, 40);
    sfText_setString(money_text->text,
    my_strcat(my_getstr(money), "$"));
    sfText_setFillColor(money_text->text, sfYellow);
    sfText_setOutlineThickness(money_text->text, 1);
    sfText_setPosition(money_text->text, get_offset(912, 10));
}

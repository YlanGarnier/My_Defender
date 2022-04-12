/*
** EPITECH PROJECT, 2022
** fonts.c
** File description:
** fonts
*/

#include "my_defender.h"
#include "menu.h"

font_t get_title_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 150);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "Castle defender");
    sfText_setPosition(font.text, get_offset(550, 100));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

font_t get_play_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "Play");
    sfText_setPosition(font.text, get_offset(800, 400));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

font_t get_quit_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "Quit");
    sfText_setPosition(font.text, get_offset(800, 700));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

font_t get_leader_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "Leaderboard");
    sfText_setPosition(font.text, get_offset(800, 600));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

font_t get_settings_font(void)
{
    font_t font;

    font.text = sfText_create();
    font.font = sfFont_createFromFile("fonts/menu.ttf");
    sfText_setFont(font.text, font.font);
    sfText_setCharacterSize(font.text, 75);
    sfText_setFillColor(font.text, sfColor_fromRGB(70, 70, 90));
    sfText_setString(font.text, "Settings");
    sfText_setPosition(font.text, get_offset(800, 500));
    sfText_setOutlineThickness(font.text, 0);
    return font;
}

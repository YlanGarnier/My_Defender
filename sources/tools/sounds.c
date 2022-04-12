/*
** EPITECH PROJECT, 2022
** sounds
** File description:
** all functions about sounds
*/

#include "my_defender.h"

void set_sounds(window_t *window)
{
    window->sound[0].music = sfMusic_createFromFile("sounds/menu_music.ogg");
    sfMusic_setLoop(window->sound[0].music, sfTrue);
    window->sound[1].music = sfMusic_createFromFile("sounds/game_music.ogg");
    sfMusic_setLoop(window->sound[1].music, sfTrue);
    window->sound[2].buffer = sfSoundBuffer_createFromFile
    ("sounds/parchment.ogg");
    window->sound[3].buffer = sfSoundBuffer_createFromFile("sounds/click.ogg");
    window->sound[2].sound = sfSound_create();
    window->sound[3].sound = sfSound_create();
    sfSound_setBuffer(window->sound[2].sound, window->sound[2].buffer);
    sfSound_setBuffer(window->sound[3].sound, window->sound[3].buffer);
    return;
}

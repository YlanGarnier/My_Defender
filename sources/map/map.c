/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** all functions about map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"
#include "my_defender.h"
#include <dirent.h>

char **set_map(char *path)
{
    int fd;
    char *buffer;
    char **map;

    fd = open(path, O_RDONLY);
    buffer = malloc(sizeof(char) * (210));
    read(fd, buffer, 209);
    buffer[209] = '\0';
    map = my_str_to_word_array(buffer, '#');
    close(fd);
    return map;
}

void load_maps(window_t *window, char *str)
{
    window->map_paths = my_str_to_word_array(str, ' ');
    window->map = malloc(sizeof(char **) * window->map_nb);
    for (int i = 0; i != window->map_nb; i++) {
        window->map[i] = set_map(window->map_paths[i]);
    }
    return;
}

void get_maps(window_t *window)
{
    DIR *dir = opendir("map");
    struct dirent *ls;
    char *str = malloc(sizeof(char) * (10000));

    str[0] = '\0';
    while ((ls = readdir(dir)) != NULL)
        if (ls->d_name[0] != '.') {
            char *temp = malloc (sizeof(char) * (50));
            window->map_nb++;
            temp = my_strcpy(temp, "map/\0");
            temp = my_strcat(temp, ls->d_name);
            str = my_strcat(str, temp);
            free(temp);
        }
    load_maps(window, str);
    closedir(dir);
    return;
}

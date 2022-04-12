/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my strcmp description
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++){
        if (s1[i] != s2[i])
            return 0;
        else if (s2[i] == '\0')
            return 0;
    }
    return 1;
}

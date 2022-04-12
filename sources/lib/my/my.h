/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** library prototypes
*/

#ifndef MY_H_
    #define MY_H_

char *my_getstr(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(char *str, char c);
char *my_strcpy(char *dest, char const *src);
int is_alpha(char c);
char **my_delimiters(char *str);
void my_putstr(char const *str);
void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);

#endif /* !MY_H_ */

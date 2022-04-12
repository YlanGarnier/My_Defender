##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## a file to rule them all
##

LIB	=	my_getstr.c	\
		my_str_to_word_array.c	\
		my_strcat.c	\
		my_strlen.c	\
		my_strcpy.c	\
		my_is_alpha.c	\
		my_putstr.c	\
		my_putchar.c	\
		my_strcmp.c	\

OBJ	=	$(LIB:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../../lib
	cp my.h ../../../includes

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

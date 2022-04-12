##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## rule them all
##

CC	=	gcc

FILE	=	sources/map/textures.c	\
		sources/map/map.c	\
		sources/tools/sounds.c	\
		sources/basics/window.c	\
		sources/basics/main.c	\
		sources/basics/usage.c	\
		sources/basics/defender.c	\
		sources/basics/error_handling.c	\
		sources/game/tower_attacks.c	\
		sources/game/destroy.c	\
		sources/game/event.c	\
		sources/game/shop.c	\
		sources/game/set_game.c	\
		sources/game/display.c	\
		sources/game/tower.c	\
		sources/game/text.c	\
		sources/game/pos_monster.c	\
		sources/game/monster.c	\
		sources/game/init_monster.c	\
		sources/game/clock.c	\
		sources/game/game.c	\
		sources/game/pause_menu.c	\
		sources/tools/rect.c	\
		sources/tools/pos.c	\
		sources/tools/sprite.c	\
		sources/menu/menu.c	\
		sources/menu/fonts.c	\
		sources/menu/sprites.c	\
		sources/menu/event.c	\
		sources/menu/get_buttons.c	\
		sources/menu/display.c	\
		sources/menu/set_buttons.c	\
		sources/menu/buttons_param.c	\
		sources/menu/wheel.c	\
		sources/menu/set_wheel.c	\
		sources/menu/wheel_param.c	\
		sources/menu/animation.c	\
		sources/menu/intro.c	\
		sources/menu/throwback_button.c	\
		sources/menu/settings_buttons.c	\
		sources/menu/set_settings_buttons.c	\
		sources/menu/volume_soundbar.c	\
		sources/menu/volume_param.c	\
		sources/menu/more_button.c	\
		sources/basics/cursor.c	\

NAME	=	my_defender

OBJ	=	$(FILE:.c=.o)

VALGRIND	=	-g

LIB	=	-L ./sources/lib -lmy

CFLAGS	=	-Wextra -Wall

CSFMLFLAGS =	-l csfml-window -l csfml-system -l csfml-audio -l csfml-graphics

CPPFLAGS	=	-I ./includes

all:	defender

defender:	$(OBJ)
	make -C ./sources/lib/my
	$(CC) -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(LIB)
	@echo -e "\n\e[92mSuccessfully compiled\e[0m"

debug:	$(OBJ)
	make -C ./sources/lib/my
	$(CC) -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(VALGRIND) $(LIB)
	@echo -e "\n\e[92mHave fun :)\e[0m"

clean:
	$(RM) -f sources/*.o
	$(RM) -f sources/menu/*.o
	$(RM) -f sources/basics/*.o
	$(RM) -f sources/game/*.o
	$(RM) -f sources/tools/*.o
	$(RM) -f sources/map/*.o

fclean:	clean
	make fclean -C ./sources/lib/my
	$(RM) -f $(NAME)
	@echo -e "\n\e[92mSuccessfully cleaned\e[0m"

re:	fclean all

.PHONY: defender clean fclean re all my_defender

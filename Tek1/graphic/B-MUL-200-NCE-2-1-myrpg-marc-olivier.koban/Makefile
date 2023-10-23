##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for My RPG
##

NAME    = my_rpg

CC    = gcc

RM    = rm -f

SRC	=	sources/menu_option/*.c	\
		sources/utils/*.c	\
		sources/*.c	\
		sources/game/*.c	\
		sources/game_events/*.c	\
		sources/game_scene/*.c	\
		sources/ingame_menu/*.c	\
		sources/button/*.c	\
		sources/text/*.c	\
		sources/music/*.c	\

OBJS    = $(SRC:.c=.o)

FLAGS    = -g3 -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-graphics

LIBFLAG    = -I./include

all: fclean $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

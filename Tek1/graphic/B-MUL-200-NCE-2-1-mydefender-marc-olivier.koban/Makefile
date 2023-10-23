##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	sources/my_defender.c	\
		sources/my_lib.c		\
		sources/my_lib2.c		\
		sources/utils1.c		\
		sources/utils2.c		\
		sources/utils3.c		\
		sources/function_struct1.c	\
		sources/function_struct2.c	\
		sources/function_struct3.c	\
		sources/menu.c			\
		sources/menu_play.c		\
		sources/menu_utils.c	\
		sources/mouse.c			\
		sources/tilemap.c		\
		sources/menu_click.c	\
		sources/option_menu.c	\
		sources/play_menu.c		\
		sources/menu_pause.c	\
		sources/pathfinding.c	\
		sources/tower_menu.c	\
		sources/money_score.c	\
		sources/lose.c			\
		sources/enemy_wave.c	\
		sources/enemy_wave1.c	\
		sources/destroy.c		\
		sources/win.c			\
		sources/coding_style_option.c	\
		sources/play_menu2.c	\
		sources/tower.c			\
		sources/animate_bird.c	\

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ =	$(SRC:.c=.o)

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

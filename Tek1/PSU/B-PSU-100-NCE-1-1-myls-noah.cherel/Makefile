##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	sources/my_ls.c		\
		sources/my_lib.c	\
		sources/main_funct.c	\
		sources/ls_l.c	\
		sources/basic_ls.c	\
		sources/flags.c	\

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(SRC)
		gcc -o $(NAME) $(SRC) -I include/

clean:
	rm -f *.o*
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
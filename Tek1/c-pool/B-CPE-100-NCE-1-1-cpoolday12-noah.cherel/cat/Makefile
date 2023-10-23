##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task01
##

SRC	=	cat.c

NAME	=	cat

all: $(NAME)

NAMEDEST =	my.h

$(NAME):	$(SRC)
		cd ../lib/my/ && $(MAKE)
		gcc -o $(NAME) $(SRC) -I../include/ -L../lib/my/ -lmy

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all

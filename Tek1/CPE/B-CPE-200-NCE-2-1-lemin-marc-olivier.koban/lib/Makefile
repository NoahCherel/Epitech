##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for library
##

NAME	=	libmy.a

SRC	=	my_putstr.c		\
		my_strlen.c		\
		my_strcat.c		\
		my_strcmp.c		\
		my_strncpy.c		\
		my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../

all 	:	$(NAME)

clean	:
		$(RM) $(OBJ) *~ *# vgcore*

fclean	:	clean
		$(RM) ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

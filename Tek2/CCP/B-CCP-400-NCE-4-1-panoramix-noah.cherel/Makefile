##
## EPITECH PROJECT, 2023
## Repos
## File description:
## Makefile
##


NAME	=	panoramix
SRC	=	src/main.c	\
		src/misc.c
OBJ	=	$(SRC:.c=.o)
CXXFLAGS	=	-W -Wall -Wextra -Werror -pthread
HEADER	=	-I./include
CXX	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(HEADER)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

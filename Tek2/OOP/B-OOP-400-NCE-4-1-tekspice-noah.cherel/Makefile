##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC	=	src/main.cpp	\
		src/Parser.cpp	\
		src/Component.cpp	\
		src/Input.cpp	\
		src/Output.cpp	\
		src/Circuit.cpp	\
		src/Gates/*.cpp \



OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -Werror 

HEADER	=	-I./include

CXX	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(HEADER)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
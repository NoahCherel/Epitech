##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -fPIC -shared
CXXFLAGS += -Wextra -Wall -W
CXXFLAGS += -I./include -ggdb3

NAME = ../../lib/arcade_menu.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) -fPIC -shared $(CXXFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/arcade_menu.so

re: fclean all

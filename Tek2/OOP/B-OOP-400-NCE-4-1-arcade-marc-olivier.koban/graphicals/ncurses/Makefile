##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
## File description:
## Makefile
##

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -fPIC -shared
CXXFLAGS += -Wextra -Wall -W
CXXFLAGS += -I./include -ggdb3

NAME = ../../lib/arcade_ncurses.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -lncurses -o $(NAME) $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)

re: fclean all

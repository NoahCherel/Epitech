##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
## File description:
## Makefile
##


SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -fPIC -shared
CXXFLAGS += -Wextra -Wall -W
CXXFLAGS += -I./include -ggdb3

NAME = ../../plugins/raytracer_ambient.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(CXXFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)

re: fclean all

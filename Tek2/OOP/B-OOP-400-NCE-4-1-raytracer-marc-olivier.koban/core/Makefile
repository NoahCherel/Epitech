##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
## File description:
## Makefile
##

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -std=c++20 -ldl -lpthread -lm
CXXFLAGS += -Wextra -Wall -W
CXXFLAGS += -I./include -ggdb3
CXXFLAGS += -lconfig -lconfig++

LIBFLAGS += -lsfml-graphics -lsfml-window -lsfml-system

NAME = ../raytracer

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIBFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)

re: fclean all

.PHONY : all clean fclean re

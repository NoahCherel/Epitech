##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -std=c++20 -ldl -lpthread -lm
CXXFLAGS += -Wextra -Wall -W
CXXFLAGS += -I./inc -ggdb3

CXX = g++

NAME = plazza

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)

re: fclean all

.PHONY : all clean fclean re

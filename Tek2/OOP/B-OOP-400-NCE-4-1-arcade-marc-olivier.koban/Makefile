##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
## File description:
## Makefile
##

CORE_SRC	=	$(wildcard core/src/*.cpp)

CXXFLAGS	+=	-I./core/include -ggdb3
CXXFLAGS	+=	-Wextra -Wall -W
CXXFLAGS	+=	-ldl -fno-gnu-unique

OBJ 		=	$(CORE_SRC:.cpp=.o)

NAME		=	arcade

all: core graphicals games

core: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

graphicals:	$(NAME)
			@make -C graphicals/ --no-print-directory

games:	$(NAME)
		@make -C games/ --no-print-directory

clean:
	rm -f $(OBJ)
	@make clean -C graphicals/ --no-print-directory
	@make clean -C games/ --no-print-directory

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	@make fclean -C graphicals/ --no-print-directory
	@make fclean -C games/ --no-print-directory

re: fclean all

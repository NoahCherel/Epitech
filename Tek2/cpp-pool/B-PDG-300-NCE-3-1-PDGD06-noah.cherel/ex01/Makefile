##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

C_FILES=*.cpp

PROJECT_BIN = MyCat

################################################################################

all: $(PROJECT_BIN)
	g++ -o $(PROJECT_BIN) *.cpp

all: $(PROJECT_BIN)

clean:
	rm -f $(PROJECT_BIN)
	rm -f z.o
	rm -f *.hi *.o
.PHONY: clean

fclean: clean
	rm -f $(PROJECT_BIN)
.PHONY: fclean

re: fclean all

##
## EPITECH PROJECT, 2023
## piscine
## File description:
## Makefile
##

HASKELL_FILES := DoOp.hs

PROJECT_BIN=doop

################################################################################

$(PROJECT_BIN): $(HASKELL_FILES)
	ghc -o $(PROJECT_BIN) $(HASKELL_FILES)

all: $(PROJECT_BIN)

clean:
	rm -f $(PROJECT_BIN)
	rm -f *.hi *.o
.PHONY: clean

fclean: clean
	rm -f $(PROJECT_BIN)
.PHONY: fclean

re: fclean all

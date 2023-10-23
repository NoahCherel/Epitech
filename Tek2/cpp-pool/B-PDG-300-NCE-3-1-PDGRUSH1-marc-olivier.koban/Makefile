##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile for Haskell projects
##

all: pushswap_checker

pushswap_checker: checker.hs
	ghc -o pushswap_checker checker.hs

run: pushswap_checker
	./pushswap_checker

clean:
	rm -f pushswap_checker checker.hi checker.o

fclean: clean
	rm -f pushswap_checker

re: fclean pushswap_checker run

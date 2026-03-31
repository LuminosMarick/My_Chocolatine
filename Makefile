##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Made By Ozy
##
CC      =       epiclang

SRC	=	src/built_in.c \
                src/parsing.c \
                src/manage_shell.c \
                utils/first_base_functions.c \
                utils/base_functions.c \
                utils/utils.c \
                src/path.c \
                src/handling.c \
                src/pipe.c \
                src/redirection.c \

EXEC    =       mysh

P	=	unit_tests

all:
	$(CC) $(SRC) src/minishell.c -o $(EXEC) -I./minishell.h
	@echo -AoV "\033[34;47mCompilation Well Done.\033[0m"
clean:
	rm -f *.gcno *.gcda
fclean:	clean
	rm -f $(NAME)
	rm -f $(P)
	rm -f $(EXEC)
	rm -f tests/*.o
	rm -f tests/*.c~
	@echo -AoV "\033[31;47mRemoving Fully Completed.\033[0m"
re:	fclean all

unit_tests: fclean $(NAME)
	$(CC) $(SRC) tests/unit_tests.c -o unit_tests --coverage -lcriterion
	@echo -AoV "\033[34;47mExecuting Tests.\033[0m"

tests_run: unit_tests
	@./unit_tests
	@echo -AoV "\033[33;47mTests Done successfuly.\033[0m"

.PHONY:	clean fclean re all tests_run

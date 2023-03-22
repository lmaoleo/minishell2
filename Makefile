##
## EPITECH PROJECT, 2023
## minishell1
## File description:
## makefile
##

NAME = mysh

SRC = mysh.c \
		builtins_functions.c \
		str_utils.c \
		execute_bin.c \

LIBFLAG = -L./lib/my -lmy -I./include

OBJ = $(SRC:.c=.o)

MAKELIB = cd lib/my && make

$(NAME): $(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(OBJ) $(LIBFLAG)

all: $(NAME)

clean:
	$(MAKELIB) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re: fclean all

debug: fclean
	$(MAKELIB) debug
	gcc -o $(NAME) $(SRC) $(LIBFLAG) -g3

.PHONY: all clean fclean re

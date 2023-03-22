##
## EPITECH PROJECT, 2023
## minishell1
## File description:
## makefile
##

NAME = libmy.a

SRC = my_strlen.c \
		my_putstr.c \
		my_putchar.c \
		my_putnbr.c \
		my_strdup.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcat.c \
		my_realoc.c \
		my_linklist.c \

LIBFLAG = -I./include

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -c $(SRC) $(LIBFLAG)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	gcc -c $(SRC) $(LIBFLAG) -g3
	ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

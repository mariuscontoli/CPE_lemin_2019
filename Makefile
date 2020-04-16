##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for executable
##

CC =	gcc

NAME =		lem_in

SRC =		src/main.c\
			src/is.c\
			src/get.c\
			src/ants.c\
			src/init.c\
			src/check.c\
			src/parse.c\
			src/get_next_line.c\
			src/utils.c\
			src/utils2.c\
			my_printf/my_printf.c\
			my_printf/print_chars.c\
			my_printf/print_ints.c\
			my_printf/print_ints2.c\
			my_printf/utils.c\
			my_printf/utils2.c\

OBJ =		$(SRC:.=.o)

all : $(NAME)

%.o: %.c
		$(CC) -o $@ -c $<

$(NAME): $(OBJ)
		$(CC) -o $@ $^ -lm

clean:
		rm -rf src/*.o
		rm -rf my_printf/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all test clean
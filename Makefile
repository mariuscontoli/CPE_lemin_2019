##
## EPITECH PROJECT, 2019
## Working Makefile
## File description:
## Makefile
##

NAME	= 	lem_in

NAME2	=	a

SRC	=	./src/main.c\
		./src/usefull.c\
		./src/set.c\

OBJS	=	$(SRC:.c=.o)

CFLAGS =	-g3 -W -Wextra -I ./include

all : $(NAME)

$(NAME):	$(OBJS)
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -g

$(NAME2):	$(OBJS)
			gcc -o $(NAME2) $(OBJS) $(CFLAGS) -g

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME2)

re: fclean all

wh:	$(NAME2)
	rm -f $(OBJS)
##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## task 05 day 5 find square root
##
SRC	=	my_putstr.c \
		my_putchar.c \
		print_functions.c \
		mini_printf2.c \
		my_put_nbr.c\


HEADER	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f *.o
	rm -f *~
	rm -f "#*#"
	rm -f *gcda
	rm -f *gcno

fclean: clean
	rm -f $(NAME)

re:	fclean all

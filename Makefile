##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## task 05 day 5 find square root
##
SRC	=	my_revstr.c\
        my_nbr_to_str.c\
        my_hunter.c\
		initiators.c\
		main.c\
		updater.c\
		initiators_value.c\
		detecter.c\


OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

WFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	make re -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g3 -lmy -L lib/my

clean:
	rm -f *.o
	rm -f *~
	rm -f "#*#"
	rm -f *gcda
	rm -f *gcno

fclean: clean
	rm -f $(NAME)

re:	fclean all

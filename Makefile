##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for my_runner
##

CC =	gcc

NAME	=	my_runner

SRC	=	src/main.c\
		src/window.c\
		src/scene.c\
		src/events.c\
		src/init.c\
		src/init2.c\
		src/load.c\
		src/load_game.c\
		src/load_parallax.c\
		src/game.c\
		src/load_intro.c\
		src/display_intro.c\
		src/display.c\
		src/parallax.c\
		src/animate.c\
		src/cleanup.c\
		src/colliding.c\
		src/utils.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -lm

all:	$(NAME)

%.o: %.c
	$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

clean:
	rm -rf src/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
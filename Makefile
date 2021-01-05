##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC 	=	src/main.c 				\
			src/initialization.c 	\
			src/my_strcat.c			\
			src/my_strdup.c			\
			src/my_strlen.c			\
			src/my_revstr.c 		\
			src/int_to_str.c		\
			src/my_putstr.c			\
			src/my_strcmp.c 		\
			src/event_and_life.c	\
			src/map.c				\
			src/sprites.c			\

NAME	=	my_runner

CC = gcc -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) -l csfml-audio -l csfml-network -l csfml-graphics -l csfml-window -l csfml-system

fclean:
		rm -rf $(NAME)

re:		fclean all

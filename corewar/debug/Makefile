##
## Makefile for matchsitck in /home/arthur/B2/CPE/CPE_2016_matchstick/
##
## Made by Arthur Chaloin
## Login   <arthur.chaloin@epitech.eu>
##
## Started on  Fri Feb 17 15:06:59 2017 Arthur Chaloin
## Last update Wed Mar 29 18:03:00 2017 Arthur Chaloin
##

NAME	=	bbw
LNAME	=	../../bin/vm.a

CFLAGS	=	-W -Wall -Wextra -I./include/ -I../include/ -I../../include/ -g

LDFLAGS	=	-L../../lib/ -lmy -lvector -lpthread -lcsfml-graphics -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-window -lsfml-system -lX11

SRC	=	src/main.c	\
		src/video.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ../
		$(CC) $(OBJ) $(LNAME) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ../

fclean: clean
	make fclean -C ../
	rm -f bbw

re:	fclean all

##
## Makefile for matchsitck in /home/arthur/B2/CPE/CPE_2016_matchstick/
##
## Made by Arthur Chaloin
## Login   <arthur.chaloin@epitech.eu>
##
## Started on  Fri Feb 17 15:06:59 2017 Arthur Chaloin
## Last update Sun Apr  2 23:32:36 2017 Thomas ARBONA
##

NAME	=	asm
LNAME	=	../bin/asm.a

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -I../include -I./include/

LDFLAGS	=	-L../lib/ -lmy -lvector

SRC	=	src/lib/io/io.c				\
		src/lib/io/init.c			\
		src/lib/io/input.c			\
		src/lib/io/output.c			\
		src/lib/endian/helper.c			\
		src/lib/endian/force.c			\
		src/lib/header/header.c			\
		src/lib/body/precompile/precompile_1.c	\
		src/lib/body/precompile/precompile_2.c	\
		src/lib/body/precompile/precompile_3.c	\
		src/lib/body/precompile/core.c		\
		src/lib/body/precompile/label.c		\
		src/lib/body/precompile/replace.c	\
		src/lib/body/precompile/check.c		\
		src/lib/body/parameters.c		\
		src/lib/body/body.c			\
		src/lib/log/error.c			\
		src/lib/log/warning.c			\
		src/lib/op.c				\
		src/lib/helper.c			\
		src/lib/asm.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(LNAME) $(OBJ)
		$(CC) src/main.c $(LNAME) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(LNAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

fast:		CFLAGS += -O3 -Ofast -Wno-maybe-uninitialized -Wno-unused-result
fast:		re

.PHONY:		all clean fclean re

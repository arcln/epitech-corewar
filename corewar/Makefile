##
## Makefile for matchsitck in /home/arthur/B2/CPE/CPE_2016_matchstick/
##
## Made by Arthur Chaloin
## Login   <arthur.chaloin@epitech.eu>
##
## Started on  Fri Feb 17 15:06:59 2017 Arthur Chaloin
## Last update Wed Mar 29 21:38:55 2017 Arthur Chaloin
##

NAME	=	corewar
LNAME	=	../bin/libvm.a

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -I./include/ -I../include

LDFLAGS	=	-L../lib/ -lmy -lvector

SRC	=	src/core/core.c		\
		src/core/dump.c		\
		src/core/vm.c		\
		src/core/op/live.c	\
		src/core/op/ld.c	\
		src/core/op/st.c	\
		src/core/op/add.c	\
		src/core/op/sub.c	\
		src/core/op/and.c	\
		src/core/op/or.c	\
		src/core/op/xor.c	\
		src/core/op/zjmp.c	\
		src/core/op/ldi.c	\
		src/core/op/sti.c	\
		src/core/op/fork.c	\
		src/core/op/lld.c	\
		src/core/op/lldi.c	\
		src/core/op/lfork.c	\
		src/core/op/aff.c	\
		src/core/interface.c	\
		src/champion/champion.c	\
		src/champion/load.c	\
		src/utils.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(LNAME) $(OBJ)
		$(CC) src/main.c $(LNAME) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(LNAME)

re:	fclean all

debug:	CFLAGS += -g
debug:	re

fast:	CFLAGS += -O3 -Ofast -Wno-maybe-uninitialized -Wno-unused-result
fast:	re

.PHONY:	all clean fclean re

##
## Makefile for matchstick in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_mathcstick/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Thu Feb 16 13:38:18 2017 Paul Laffitte
## Last update Tue Apr 25 11:16:48 2017 Arthur Chaloin
##

OBOBNAME		=	bbw

CC		=	gcc

RM		=	rm -f

SRCS		=	src/main.c			\
			src/gui/window.c		\
			src/gui/errors.c		\
			src/gui/winner.c		\
			src/gui/events/choose_champ.c	\
			src/gui/events/clear.c		\
			src/gui/events/on_key_pressed.c	\
			src/math/vector.c		\
			src/math/matrix.c		\
			src/3d/model.c			\
			src/3d/music.c			\
			src/3d/movements.c		\
			src/3d/load_shader.c		\
			src/3d/init_gl.c		\
			src/3d/render_gl.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include -I../include -I../corewar/include `pkg-config --cflags gtk+-3.0`

LFLAGS		=	-lm -L../bin/ -lvm -lfmod -L../lib -lmy -lvector `pkg-config --libs gtk+-3.0 glew` -framework OpenGL

all:		$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(NAME):	all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

%.o: 	%.c
	gcc $(CFLAGS) -c $< -o $@

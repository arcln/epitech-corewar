##
## Makefile for bbw in /home/arbona/tek1/CPE/CPE_2016_corewar
##
## Made by Thomas ARBONA
## Login   <thomas.arbona@epitech.eu>
##
## Started on  Thu Mar 16 10:07:49 2017 Thomas ARBONA
## Last update Fri Mar 24 13:47:18 2017 John Doe
##

all:
		make -C ./lib/
		make -C ./asm/
		make -C ./corewar/
		make -C ./bbw/

clean:
		make clean -C ./lib/
		make clean -C ./asm/
		make clean -C ./corewar/
		make clean -C ./bbw/

fclean:
		make fclean -C ./lib/
		make fclean -C ./asm/
		make fclean -C ./corewar/
		make fclean -C ./bbw/

re:
		make re -C ./lib/
		make re -C ./asm/
		make re -C ./corewar/
		make re -C ./bbw/

.PHONY:	all clean fclean re

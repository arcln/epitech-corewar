/*
** dump.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Mar  1 15:12:53 2017 Arthur Chaloin
** Last update Thu Mar 30 19:03:03 2017 Paul Laffitte
*/
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

void	core_dump_memory(t_corewar *core)
{
  int	index;
  int	index2;

  index = -1;
  while (++index < MEM_SIZE)
    {
      index2 = -1;
      my_printf((index) ? "%X\t: " : "%c\t: ", (index) ? index : '0');
      while (++index2 < 32)
	my_printf("%02X ", core->mem[index + index2]);
      my_printf("\n");
      index += index2 - 1;
    }
  core->cycle = -1;
  exit(0);
}

/*
** lfork.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:32:53 2017 John Doe
** Last update Mon Mar 27 15:35:00 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "error.h"
#include "my.h"

void		op_lfork(t_corewar *core, t_champion *champion, t_pc *pc)
{
  int		index;
  int		start;
  t_pc		*new;

  if (!(new = malloc(sizeof(t_pc))))
    throw_error("Can't perform malloc.\n");
  start = read_bytes(core, IND_SIZE, pc->pos + 1);
  index = -1;
  while (++index < REG_NB)
    new->reg[index] = pc->reg[index];
  new->pos = pc->pos + start;
  new->carry = pc->carry;
  new->state = -1;
  vector_push(&(champion->pc), new);
  pc->pos += IND_SIZE;
}

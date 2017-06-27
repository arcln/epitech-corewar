/*
** and.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:29:31 2017 John Doe
** Last update Fri Mar 31 18:35:06 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_and(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  char		args[4];
  int		argv[3];

  pc->start = pc->pos;
  read_args(core->mem[pos(pc->pos + 1)], args);
  pc->pos += 1;
  argv[0] = op_read_data(core, pc, args[0], 0);
  pc->pos += SIZE(args[0]);
  argv[1] = op_read_data(core, pc, args[1], 0);
  pc->pos += SIZE(args[1]);
  argv[2] = read_bytes(core, 1, pc->pos + 1);
  pc->pos += 1;
  if (argv[2] > 0 && argv[2] <= REG_NB)
    {
      pc->reg[argv[2]] = argv[0] & argv[1];
      if (!pc->reg[argv[2]])
	pc->carry = 1;
      else
	pc->carry = 0;
    }
}

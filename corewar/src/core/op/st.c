/*
** st.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:24:40 2017 John Doe
** Last update Tue Mar 28 16:36:07 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_st(t_corewar *core, t_champion *champion, t_pc *pc)
{
  int	reg_nb[2];
  int	address;
  char	args[4];

  read_args(core->mem[pos(pc->pos + 1)], args);
  reg_nb[0] = read_bytes(core, 1, pc->pos + 2);
  if (reg_nb[0] < REG_NB && reg_nb[0] >= 0)
    {
      if (args[1] == T_IND)
	{
	  address = read_bytes(core, IND_SIZE, pc->pos + 3) % IDX_MOD;
	  write_bytes(core, REG_SIZE, pc->pos + address, pc->reg[reg_nb[0]]);
	  core->poss[pos(pc->pos + address)] = champion->id;
	  core->poss[pos(pc->pos + address + 1)] = champion->id;
	  core->poss[pos(pc->pos + address + 2)] = champion->id;
	  core->poss[pos(pc->pos + address + 3)] = champion->id;
	}
      else
	{
	  reg_nb[1] = read_bytes(core, 1, pc->pos + 3);
	  if (reg_nb[1] <= REG_NB && reg_nb[1] > 0)
	    pc->reg[reg_nb[1]] = pc->reg[reg_nb[0]];
	}
    }
  pc->pos += 2 + SIZE(args[1]);
}

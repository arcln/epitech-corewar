/*
** add.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Mar 27 11:42:53 2017 John Doe
** Last update Tue Mar 28 18:58:39 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_add(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  int		reg_nb[3];

  reg_nb[0] = read_bytes(core, 1, pc->pos + 2);
  reg_nb[1] = read_bytes(core, 1, pc->pos + 3);
  reg_nb[2] = read_bytes(core, 1, pc->pos + 4);
  if (reg_nb[0] <= REG_NB && reg_nb[0] > 0 &&
      reg_nb[1] <= REG_NB && reg_nb[1] > 0 &&
      reg_nb[2] <= REG_NB && reg_nb[2] > 0)
    {
      pc->reg[reg_nb[2]] = pc->reg[reg_nb[0]] + pc->reg[reg_nb[0]];
      if (!pc->reg[reg_nb[2]])
	pc->carry = 1;
      else
	pc->carry = 0;
    }
  pc->pos += 4;
}

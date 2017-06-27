/*
** lld.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:31:54 2017 John Doe
** Last update Tue Mar 28 16:02:43 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_lld(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  int	reg_nb;
  int	value;
  int	address;
  char	args[4];

  read_args(core->mem[pos(pc->pos + 1)], args);
  if (args[0] == T_DIR)
    {
      value = read_bytes(core, DIR_SIZE, pc->pos + 2);
      pc->pos += DIR_SIZE;
    }
  else
    {
      address = read_bytes(core, IND_SIZE, pc->pos + 2);
      value = read_bytes(core, REG_SIZE, pc->pos + address);
      pc->pos += IND_SIZE;
    }
  reg_nb = read_bytes(core, 1, pc->pos + 2);
  pc->pos += 2;
  if (reg_nb <= REG_NB && reg_nb > 0)
    pc->reg[reg_nb] = value;
  if (!value)
    pc->carry = 1;
  else
    pc->carry = 0;
}

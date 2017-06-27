/*
** read.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Mar  2 12:56:52 2017 Arthur Chaloin
** Last update Fri Mar 31 18:34:19 2017 Arthur Chaloin
*/
#include "define.h"
#include "corewar.h"
#include "exec.h"

int	op_read_data(t_corewar *core, t_pc *pc, char args, int cast)
{
  int	data;

  data = 0;
  if (args == T_REG)
    {
      data = read_bytes(core, 1, pc->pos + 1);
      if (data >= 0 && data < REG_NB)
	data = pc->reg[data];
      else
	data = 0;
    }
  else if (args == T_IND)
    {
      data = read_bytes(core, IND_SIZE, pc->pos + 1);
      data = read_bytes(core, REG_SIZE, pc->start + data);
    }
  else
    data = read_bytes(core, (cast) ? IND_SIZE : DIR_SIZE, pc->pos + 1);
  return (data);
}

void		read_args(char raw, char args[4])
{
  args[0] = raw >> 6 & 3;
  args[1] = raw >> 4 & 3;
  args[2] = raw >> 2 & 3;
  args[3] = raw & 3;
}

int		read_bytes(t_corewar *core, int size, int address)
{
  int		index;
  int		index2;
  t_transfer	common;

  index = size;
  index2 = -1;
  common.nb = 0;
  while (++index2 < size)
    common.s_nb[--index] = core->mem[pos(address + index2)];
  return ((size == 2) ? common.l_nb : common.nb);
}

void		write_bytes(t_corewar *core, int size, int address, int value)
{
  int		index;
  t_transfer	common;

  common.nb = value;
  index = -1;
  while (++index < size)
    core->mem[pos(address + index)] = common.s_nb[size - index - 1];
}

/*
** zjmp.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:30:46 2017 John Doe
** Last update Tue Mar 28 16:01:29 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_zjmp(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  int		address;

  if (pc->carry)
    {
      address = read_bytes(core, IND_SIZE, pc->pos + 1);
      pc->pos += address % IDX_MOD - 1;
    }
}

/*
** aff.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 24 14:32:40 2017 John Doe
** Last update Tue Mar 28 15:20:55 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

void		op_aff(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  int		reg_nb;

  reg_nb = read_bytes(core, 1, pc->pos + 2);
  if (reg_nb <= REG_NB && reg_nb > 0)
    my_printf("%d\n", pc->reg[reg_nb] % 256);
  pc->pos += 2;
}

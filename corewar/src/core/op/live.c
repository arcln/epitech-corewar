/*
** live.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/op/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Mar  2 11:51:12 2017 Arthur Chaloin
** Last update Tue Mar 28 15:15:08 2017 Arthur Chaloin
*/
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

#include <stdio.h>

void		op_live(t_corewar *core,
		       __attribute__((unused))t_champion *champion,
		       t_pc *pc)
{
  int		nb;
  t_champion	*champ;

  nb = read_bytes(core, 4, pc->pos + 1);
  champ = champion_find(core, nb);
  if (champ)
    {
      my_printf("The player %d(%s) is alive.\n", nb, champ->header.name);
      champ->last_live = 0;
    }
  pc->pos += 4;
}

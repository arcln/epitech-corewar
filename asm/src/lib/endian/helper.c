/*
** helper.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 14:31:56 2017 Thomas ARBONA
** Last update Tue Mar 28 19:12:45 2017 Thomas ARBONA
*/
#include "lib/endian/force.h"

static int	_endian_isbig()
{
  t_revi16	rev;

  rev.i = 1;
  return (rev.c[1] == 1);
}

int		endian_isbig()
{
  static int	flag = -1;

  if (flag == -1)
    flag = _endian_isbig();
  return (flag);
}

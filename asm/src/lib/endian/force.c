/*
** force.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 14:44:56 2017 Thomas ARBONA
** Last update Sun Apr  2 20:31:52 2017 Thomas ARBONA
*/
#include <stdint.h>
#include "lib/endian/force.h"
#include "lib/endian.h"

int16_t		endian_fbigi16(int16_t i)
{
  t_revi16	rev;
  char		c;

  if (endian_isbig())
    return (i);
  rev.i = i;
  c = rev.c[0];
  rev.c[0] = rev.c[1];
  rev.c[1] = c;
  return (rev.i);
}

int32_t		endian_fbigi32(int32_t i)
{
  t_revi32	rev;
  char		c;

  if (endian_isbig())
    return (i);
  rev.i = i;
  c = rev.c[0];
  rev.c[0] = rev.c[3];
  rev.c[3] = c;
  c = rev.c[1];
  rev.c[1] = rev.c[2];
  rev.c[2] = c;
  return (rev.i);
}

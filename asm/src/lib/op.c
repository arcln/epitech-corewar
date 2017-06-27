/*
** op.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 11:03:40 2017 Thomas ARBONA
** Last update Sun Apr  2 20:55:29 2017 Thomas ARBONA
*/
#include "lib/op.h"
#include "my.h"

t_op	g_ops[] = {
  {"live", 1, {T_DIR}, 1, 10, 0, 1},
  {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 0, 0},
  {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 0, 0},
  {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 0, 0},
  {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 0, 0},
  {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
   6, 6, 0, 0},
  {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   7, 6, 0, 0},
  {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   8, 6, 0, 0},
  {"zjmp", 1, {T_DIR}, 9, 20, 1, 1},
  {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 0},
  {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 0},
  {"fork", 1, {T_DIR}, 12, 800, 1, 1},
  {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 0, 0},
  {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 0},
  {"lfork", 1, {T_DIR}, 15, 1000, 1, 1},
  {"aff", 1, {T_REG}, 16, 2, 0, 0},
  {0, 0, {0}, 0, 0, 0, 0}
};

t_op	*op_get(char *name)
{
  int	index;

  index = 0;
  while (g_ops[index].mnemonique != 0)
    {
      if (my_strcmp(g_ops[index].mnemonique, name) == 0)
	break;
      index += 1;
    }
  return (&g_ops[index]);
}

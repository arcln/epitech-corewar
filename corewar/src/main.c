/*
** main.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Mon Feb 27 19:29:11 2017 Arthur Chaloin
** Last update Tue Mar 28 17:29:29 2017 Arthur Chaloin
*/
#include "define.h"
#include "corewar.h"

int	main(const int ac, char *av[])
{
  t_corewar	core;

  if (ac < 2 || vm_init(&core, ac, av))
    return (84);
  vm_start(&core);
  return (0);
}

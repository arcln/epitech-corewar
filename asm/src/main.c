/*
** main.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 11:22:37 2017 Thomas ARBONA
** Last update Sun Apr  2 21:12:36 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <fcntl.h>
#include "lib/asm.h"
#include "my.h"

int	display_help(char *bin_name)
{
  my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n\tfile_name", bin_name);
  my_printf("\tfile in assembly language to be converted into file_name.cor,");
  my_printf(" an executable in the Virtual Machine).\n");
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2)
    return (84);
  if (my_strcmp(av[1], "-h") == 0)
    return (display_help(av[0]));
  if (asm_compile(av[1], NULL, VERBOSE) == -1)
    return (84);
  return (0);
}

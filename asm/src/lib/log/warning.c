/*
** warning.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar 29 15:15:04 2017 Thomas ARBONA
** Last update Thu Mar 30 02:07:07 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/asm.h"
#include "lib/io.h"
#include "lib/log.h"
#include "my.h"

int     log_syntaxwarning(t_io *io, char *error, int mode)
{
  if (io->out.mode != VERBOSE)
    return (-1);
  (void)mode;
  my_dprintf(2, "\e[1m%s:%i:%i: \e[35mwarning:\e[39m\e[21m %s\n",
	     io->in.path, io->in.row, io->in.col, error);
  return (-1);
}

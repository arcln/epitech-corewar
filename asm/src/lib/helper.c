/*
** helper.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 15:35:55 2017 Thomas ARBONA
** Last update Tue Mar 28 18:27:23 2017 Thomas ARBONA
*/
#include <unistd.h>
#include "lib/io.h"
#include "my.h"

int	helper_posinstr(t_io *io, int i, int j)
{
  int	index;
  char	*p;
  int	shift;

  index = -1;
  p = io->in.line;
  while (io->in.split[++index] != NULL && index <= i)
    {
      shift = (index != 0)
	? my_strlen(io->in.split[index - 1])
	: 0;
      p = my_strstr(io->in.line + (p - io->in.line) + shift,
		    io->in.split[index]);
    }
  return (p - io->in.line + j);
}

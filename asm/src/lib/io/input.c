/*
** input.c for io in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar 22 11:24:05 2017 Thomas ARBONA
** Last update Sun Apr  2 20:50:59 2017 Thomas ARBONA
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib/io.h"
#include "my.h"

int g_io_backgnl = 0;

int	io_setinput(t_io *io, char *in_path)
{
  if ((io->in.fd = open(in_path, O_RDONLY)) == -1)
    return (-1);
  io->in.path = in_path;
  return (0);
}

int		io_getnextline(t_io *io)
{
  char		**split;
  int		index;

  index = 0;
  split = NULL;
  if (g_io_backgnl == 1)
    return ((g_io_backgnl = 0));
  if (io->in.row != 0 && io->in.line != NULL)
    free(io->in.line);
  while (index == 0 ||
	 (io->in.line != NULL && (io->in.line[0] == 0 || split[0] == NULL)))
    {
      io->in.line = get_next_line(io->in.fd);
      if (index != 0)
	free_tab((void**)split, -1);
      if (io->in.line != NULL)
	split = my_strsplit(io->in.line, "\t ");
      io->in.row += 1;
      index += 1;
    }
  if (io->in.line != NULL)
    free_tab((void**)split, -1);
  io->in.col = 0;
  return (io->in.line != NULL ? 0 : -1);
}

void	io_destroybody(t_io *io)
{
  int	index;

  index = 0;
  while (index < vector_getsize(&io->in.body))
    {
      free(vector_get(&io->in.body, index, char));
      index += 1;
    }
  vector_free(&io->in.body);
}

int		io_gnlbody(t_io *io)
{
  static int	nline = 0;

  if (g_io_backgnl == 1)
    return ((g_io_backgnl = 0));
  if (nline >= vector_getsize(&io->in.body))
    {
      io->in.line = NULL;
      io->in.row = -1;
      nline = 0;
      return (-1);
    }
  while (!(io->in.line = vector_get(&io->in.body, nline, char)))
    {
      if (nline >= vector_getsize(&io->in.body))
	{
	  io->in.line = NULL;
	  io->in.row = -1;
	  nline = 0;
	  return (-1);
	}
      nline += 1;
    }
  io->in.row = nline + io->in.head_row + 1;
  nline += 1;
  return (0);
}

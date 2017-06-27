/*
** error.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar 22 14:33:04 2017 Thomas ARBONA
** Last update Sun Apr  2 20:59:24 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/asm.h"
#include "lib/io.h"
#include "lib/log.h"
#include "my.h"

static int      normalize_col(t_io *io)
{
  char		*normline;
  int		index;
  int		n;
  int		limit;

  index = 0;
  n = 0;
  limit = io->in.col;
  io->in.line = my_strdup(io->in.line);
  while (index < limit)
    {
      n += 1;
      if (io->in.line[index] == '\t')
	{
	  normline = my_str_replace(io->in.line, index, index, "        ");
	  free(io->in.line);
	  io->in.line = normline;
	  index += 7;
	  limit += 7;
	  n += 7;
	}
      index += 1;
    }
  return (n);
}

static void	display_shift(char c, int col)
{
  char		buff[512];

  my_memset(buff, c, col + 1);
  write(2, buff, my_strlen(buff));
}

static void	handle_cursor(t_io *io, int ncol, int mode)
{
  char	*b;

  b = my_strndup(io->in.line + ncol, 1 +
		 (mode == 2 ? io->in.cursor - 1 : 0));
  io->in.line[ncol] = 0;
  my_dprintf(2, " %s\e[1m\e[31m%s\e[39m\e[21m%s\n",
	     io->in.line, b, io->in.line + ncol +
	     (mode == 2 ? io->in.cursor : 1));
  display_shift(' ', ncol + 1);
  write(2, "\e[1m\e[31m^", 10);
  if (mode == 2)
    display_shift('~', io->in.cursor - 1);
  write(2, "\e[0m\n", 5);
  free(b);
}

int	log_syntaxerror(t_io *io, char *error, int mode)
{
  int	ncol;
  char	*errf;
  char	*arg;

  if (io->out.mode != VERBOSE)
    return (-1);
  ncol = normalize_col(io);
  arg = my_strndup(io->in.line + ncol, io->in.cursor);
  errf = my_asprintf(error, arg);
  my_dprintf(2, "\e[1m%s:%i:%i: \e[31merror:\e[39m\e[21m %s\n",
	     io->in.path, io->in.row, io->in.col, errf);
  free(errf);
  free(arg);
  if (mode)
    handle_cursor(io, ncol, mode);
  free(io->in.line);
  return (-1);
}

int	log_builderror(t_io *io)
{
  if (io->out.mode != VERBOSE)
    return (-1);
  my_dprintf(2, "Recipe for target '%s' failed\n", io->out.path);
  return (-1);
}

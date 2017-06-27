/*
** precompile_3.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Apr  2 23:36:09 2017 Thomas ARBONA
** Last update Fri Apr  7 11:52:12 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/body/precompile.h"
#include "lib/body.h"
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/helper.h"
#include "my.h"

static void	handle_labeldef(t_io *io)
{
  char		*tmp;

  if (is_labeldef(io->in.split[0]))
    {
      tmp = my_strdup(io->in.line + my_strlen(io->in.split[0]));
      REAFFECT(io->in.line, tmp);
      free_tab((void**)io->in.split, -1);
      io->in.split = my_strsplit(io->in.line, " \t,");
    }
}

static void	handle_replacelabel(t_io *io, t_vector *labels,
				    int *_nbytes, t_op *op)
{
  int		index;
  int		nbytes;

  index = 0;
  nbytes = *_nbytes;
  nbytes -= (1 + (!op->no_codingbyte));
  while (io->in.split[++index] != NULL)
    {
      if (io->in.split[index][0] == LABEL_CHAR ||
	  io->in.split[index][1] == LABEL_CHAR)
	replace_label(io, labels, index, nbytes);
      *_nbytes += ARG_OUTSIZE(arg_gettype(io, io->in.split[index], 0),
			     op->index_arg);
    }
}

int		precompile_3(t_io *io, t_vector *labels)
{
  int           nbytes;
  int           _nbytes;
  t_op          *op;

  nbytes = 0;
  io->in.labelised = 0;
  while (io_gnlbody(io) != -1)
    {
      _nbytes = nbytes;
      io->in.split = my_strsplit(io->in.line, " \t,");
      if (!replace_comment(io))
	{
	  handle_labeldef(io);
	  if (io->in.split[0] != NULL)
	    {
	      op = op_get(io->in.split[0]);
	      _nbytes += (1 + (!op->no_codingbyte));
	      handle_replacelabel(io, labels, &_nbytes, op);
	    }
	  else
	    io->in.line = NULL;
	}
      nbytes = _nbytes;
      vector_set(&io->in.body, io->in.row - io->in.head_row - 1, io->in.line);
    }
  return (0);
}

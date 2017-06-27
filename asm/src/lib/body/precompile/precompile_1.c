/*
** precompile_1.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Apr  2 23:06:33 2017 Thomas ARBONA
** Last update Sun Apr  2 23:33:46 2017 Thomas ARBONA
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

static int	handle_label(t_io *io, t_vector *labels, int nbytes)
{
  io->in.labelised = 1;
  io->in.split[0][my_strlen(io->in.split[0]) - 1] = 0;
  if (label_get(labels, io->in.split[0]))
    {
      io->in.col = helper_posinstr(io, 0, 0);
      io->in.cursor = my_strlen(io->in.split[0]);
      return (log_syntaxerror(io, SERR_ALDEF_LABEL, 2));
    }
  vector_push(labels, label_create(io->in.split[0], nbytes));
  return (0);
}

int		precompile_1(t_io *io, t_vector *labels)
{
  int           nbytes;
  int           shift;

  nbytes = 0;
  while (io_gnlbody(io) != -1)
    {
      shift = 0;
      io->in.labelised = 0;
      io->in.split = my_strsplit(io->in.line, " ,\t");
      if (replace_commentsplit(io))
	continue;
      if (is_labeldef(io->in.split[0]))
	{
	  if (handle_label(io, labels, nbytes) == -1)
	    return (-1);
	  shift = 1;
	}
      if (!(shift == 1 && io->in.split[1] == NULL) &&
	  body_checkline(io, shift, &nbytes) == -1)
	return (-1);
      free_tab((void**)io->in.split, -1);
    }
  return (0);
}

/*
** precompile_2.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Apr  2 23:15:01 2017 Thomas ARBONA
** Last update Sun Apr  2 23:15:46 2017 Thomas ARBONA
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

int		precompile_2(t_io *io, t_vector *labels)
{
  int           shift;
  t_op          *op;

  while (io_gnlbody(io) != -1)
    {
      shift = 0;
      io->in.split = my_strsplit(io->in.line, " ,\t");
      if (replace_commentsplit(io))
	continue;
      if (is_labeldef(io->in.split[0]))
	shift += 1;
      if (io->in.split[shift] != NULL)
	{
	  op = op_get(io->in.split[shift]);
	  if (!label_checkargs(io, labels, op, shift))
	    return (log_syntaxerror(io, SERR_UNDEF_LABEL, 2));
	}
      free_tab((void**)io->in.split, -1);

    }
  return (0);
}

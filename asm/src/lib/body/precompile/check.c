/*
** check.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 22:07:32 2017 Thomas ARBONA
** Last update Sun Apr  2 21:23:14 2017 Thomas ARBONA
*/
#include <unistd.h>
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/body.h"
#include "lib/helper.h"
#include "my.h"

static int	check_op(t_io *io, t_op *op)
{
  if (op->mnemonique == NULL)
    {
      io->in.col = helper_posinstr(io, 0 + io->in.labelised, 0);
      io->in.cursor = my_strlen(io->in.split[0 + io->in.labelised]);
      return (log_syntaxerror(io, SERR_UNKNOWN_OP, 2));
    }
  return (0);
}

static int	check_type(t_io *io, int bool, int index, char **params)
{
  if (!bool)
    {
      io->in.col = helper_posinstr(io, index + 1 + io->in.labelised, 0);
      io->in.cursor = my_strlen(params[index]);
      return (log_syntaxerror(io, SERR_INVALID_PARAMS, 2));
    }
  return (0);
}

int	body_checkline(t_io *io, int label, int *nbytes)
{
  int	index;
  int	type;
  t_op	*op;
  char	**params;

  if (!(op = op_get(io->in.split[0 + label])) || check_op(io, op) == -1)
    return (-1);
  *nbytes = (*nbytes) + 1 + (!op->no_codingbyte);
  index = 0;
  params = io->in.split + label + 1;
  while (index < op->nbr_args)
    {
      if ((type = arg_gettype(io, params[index], index + label + 1)) == -1 ||
	  (check_type(io, op->type[index] & type, index, params) == -1))
	return (-1);
      *nbytes += ARG_OUTSIZE(type, op->index_arg);
      index += 1;
    }
  if (params[index] != NULL)
    {
      io->in.col = helper_posinstr(io, index + 1 + label, 0);
      io->in.cursor = my_strlen(params[index]);
      return (log_syntaxerror(io, SERR_UNEXP_PARAMS, 2));
    }
  return (0);
}

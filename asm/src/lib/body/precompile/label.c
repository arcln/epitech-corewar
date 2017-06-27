/*
** label.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 23:56:53 2017 Thomas ARBONA
** Last update Thu Mar 30 02:09:08 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/body/precompile.h"
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/helper.h"
#include "my.h"

static int	label_serrsetcurs(t_io *io, int index)
{
  io->in.col = helper_posinstr(io, index, 0);
  io->in.cursor = my_strlen(io->in.split[index]);
  return (0);
}

t_label		*label_get(t_vector *labels, char *label_name)
{
  int		index;
  t_label	*label;

  index = -1;
  while (++index < vector_getsize(labels))
    {
      label = vector_get(labels, index, t_label);
      if (my_strcmp(label->name, label_name) == 0)
	return (label);
    }
  return (NULL);
}

int		label_checkargs(t_io *io, t_vector *labels,
			     t_op *op, int shift)
{
  int		index;
  char		*arg;

  index = -1;
  while (++index < op->nbr_args)
    {
      arg = io->in.split[index + 1 + shift];
      if (arg[0] == DIRECT_CHAR)
	arg += 1;
      if (arg[0] != LABEL_CHAR)
	continue;
      arg += 1;
      if (!label_get(labels, arg))
	return (label_serrsetcurs(io, index + 1 + shift));
    }
  return (1);
}

t_label		*label_create(char *name, int pos)
{
  t_label       *label;

  if (!(label = malloc(sizeof(t_label))))
    return (NULL);
  label->name = my_strdup(name);
  label->pos = pos;
  return (label);
}

int		is_labeldef(char *str)
{
  int           index;

  index = -1;
  while (str[++index + 1] != 0)
    {
      if (!IS_LABCH(str[index]))
	return (0);
    }
  return (str[index] == LABEL_CHAR);
}

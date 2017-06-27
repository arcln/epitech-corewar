/*
** replace.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar 29 20:08:39 2017 Thomas ARBONA
** Last update Fri Apr  7 11:52:27 2017 Thomas ARBONA
*/
#include "lib/op.h"
#include "lib/io.h"
#include "lib/body.h"
#include "lib/body/precompile.h"
#include "lib/helper.h"
#include "vector.h"
#include "my.h"

int		replace_commentsplit(t_io *io)
{
  int		index;

  index = 0;
  while (io->in.split[index] != NULL)
    {
      if (io->in.split[index][0] == COMMENT_CHAR)
	{
	  free(io->in.split[index]);
	  io->in.split[index] = NULL;
	  if (index == 0)
	    {
	      free_tab((void**)io->in.split, -1);
	      return (1);
	    }
	  return (0);
	}
      index += 1;
    }
  return (0);
}

int		replace_comment(t_io *io)
{
  int		index;
  int		status;
  char		*tmp;

  index = 0;
  status = 0;
  while (io->in.split[index] != NULL)
    {
      if (io->in.split[index][0] == COMMENT_CHAR)
	{
	  if (index == 0)
	    {
	      status = 1;
	      REAFFECT(io->in.line, NULL);
	      break;
	    }
	  tmp = my_strndup(io->in.line, helper_posinstr(io, index, 0));
	  REAFFECT(io->in.line, tmp);
	  break;
	}
      index += 1;
    }
  free_tab((void**)io->in.split, -1);
  io->in.split = my_strsplit(io->in.line, " \t,");
  return (status);
}

void		replace_label(t_io *io, t_vector *labels, int n, int nbytes)
{
  int		is_dir;
  char		*name;
  char		*tmp;
  char		*int_str;
  t_label	*label;
  int		pos;

  is_dir = 0;
  name = io->in.split[n];
  if (name[0] == DIRECT_CHAR)
    name += (is_dir = 1);
  label = label_get(labels, name + 1);
  pos = helper_posinstr(io, n, is_dir);
  int_str = my_int_str(label->pos - nbytes);
  tmp = my_str_replace(io->in.line, pos, pos + my_strlen(name) - 1, int_str);
  REAFFECT(io->in.line, tmp);
  free(int_str);
}

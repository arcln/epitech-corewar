/*
** parameters.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 14:22:38 2017 Thomas ARBONA
** Last update Sun Apr  2 21:09:11 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdint.h>
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/helper.h"
#include "lib/endian.h"
#include "lib/body/precompile.h"
#include "my.h"

static int	arg_checklabel(t_io *io, char *arg, int i, int type)
{
  int		shift;
  int		index;

  shift = 0;
  index = 0;
  if (arg[0] == DIRECT_CHAR)
    arg += (shift += 1);
  if (arg[0] != LABEL_CHAR)
    {
      io->in.col = helper_posinstr(io, i, shift);
      return (log_syntaxerror(io, SERR_BAD_TOKEN, 1));
    }
  while (arg[++index] != 0)
    {
      if (!IS_LABCH(arg[index]))
	{
	  io->in.col = helper_posinstr(io, i, index + shift);
	  return (log_syntaxerror(io, SERR_BAD_TOKEN, 1));
	}
    }
  return (type);
}

static int	arg_checkreg(t_io *io, char *arg, int i)
{
  int		n;

  n = my_getnbr(arg + 1);
  if (!(1 <= n && n <= REG_NUMBER))
    {
      io->in.col = helper_posinstr(io, i, 0);
      io->in.cursor = my_strlen(arg);
      return (log_syntaxerror(io, SERR_INV_REG, 2));
    }
  return (0);
}

static int	arg_checkvalue(t_io *io, char *arg, int i)
{
  int		index;

  index = 0;
  while (arg[++index] == '+' || arg[index] == '-');
  index -= 1;
  while (arg[++index] != 0)
    {
      if (!('0' <= arg[index] && arg[index] <= '9'))
	{
	  io->in.col = helper_posinstr(io, i, index);
	  return (log_syntaxerror(io, SERR_BAD_TOKEN, 1));
	}
    }
  return (0);
}

int		arg_gettype(t_io *io, char *arg, int i)
{
  int		type;

  if (arg == NULL)
    {
      io->in.col = helper_posinstr(io, io->in.labelised, 0);
      io->in.cursor = my_strlen(io->in.split[io->in.labelised]);
      return (log_syntaxerror(io, SERR_MISSING_PARAMS, 0));
    }
  type = (arg[0] == DIRECT_CHAR) ? T_DIR :
    (arg[0] == 'r') ? T_REG :
    ((('0' <= arg[0] && arg[0] <= '9') || arg[0] == '-' ||
      arg[0] == '+' || arg[0] == LABEL_CHAR)) ? T_IND : -1;
  io->in.col = helper_posinstr(io, i, 0);
  if (type == -1)
    return (log_syntaxerror(io, SERR_BAD_TOKEN, 1));
  if (type == T_DIR && my_strlen(arg) == 1)
    {
      io->in.col = helper_posinstr(io, i, 0);
      return (log_syntaxerror(io, SERR_BAD_DIRARG, 1));
    }
  if (arg[0] == LABEL_CHAR ||
      (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR))
    return (arg_checklabel(io, arg, i, type));
  return (arg_checkvalue(io, arg, i) == -1 ||
	  (type == T_REG && arg_checkreg(io, arg, i) == -1)) ? -1 : type;
}

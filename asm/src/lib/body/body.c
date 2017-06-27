/*
** body.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 16:41:07 2017 Thomas ARBONA
** Last update Fri Mar 31 11:49:58 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdint.h>
#include "lib/header.h"
#include "lib/endian.h"
#include "lib/io.h"
#include "lib/op.h"
#include "lib/body.h"
#include "lib/body/precompile.h"
#include "vector.h"
#include "my.h"

static void	write_name(t_io *io, t_op *op)
{
  int8_t	name;

  name = op->code;
  io_outpush(io, &name, sizeof(int8_t));
}

static void	write_codingbyte(t_io *io, t_op *op, char **params)
{
  int		index;
  int8_t	codingbyte;
  int		type;

  index = 0;
  codingbyte = 0;
  while (index < MAX_ARGS_NB)
    {
      codingbyte = codingbyte << 2;
      if (index < op->nbr_args)
	{
	  type = arg_gettype(io, params[index], 0);
	  codingbyte += (type == T_REG) ? 1 :
	    (type == T_DIR) ? 2 : 3;
	}
      index += 1;
    }
  io_outpush(io, &codingbyte, sizeof(int8_t));
}

static void	write_argument(t_io *io, t_op *op, char *arg)
{
  int8_t	reg;
  int16_t	ind;
  int32_t	dir;
  int		type;
  int		size;

  type = arg_gettype(io, arg, 0);
  size = ARG_OUTSIZE(type, op->index_arg);
  if (size == 1)
    {
      reg = my_getnbr(arg + 1);
      io_outpush(io, &reg, sizeof(int8_t));
    }
  else if (size == 2)
    {
      ind = my_getnbr(arg + (type == T_DIR));
      ind = endian_fbigi16(ind);
      io_outpush(io, &ind, sizeof(int16_t));
    }
  else
    {
      dir = my_getnbr(arg + 1);
      dir = endian_fbigi32(dir);
      io_outpush(io, &dir, sizeof(int32_t));
    }
}

int		body_compile(t_io *io)
{
  t_op		*op;
  int		index;

  io_initbody(io);
  if (body_precompile(io) == -1)
    return (-1);
  while (io_gnlbody(io) != -1)
    {
      io->in.split = my_strsplit(io->in.line, " \t,");
      op = op_get(io->in.split[0]);
      write_name(io, op);
      if (!op->no_codingbyte)
	write_codingbyte(io, op, io->in.split + 1);
      index = -1;
      while (++index < op->nbr_args)
	write_argument(io, op, io->in.split[index + 1]);
    }
  io_destroybody(io);
  return (0);
}

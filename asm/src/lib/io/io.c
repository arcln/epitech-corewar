/*
** out.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 21 15:44:55 2017 Thomas ARBONA
** Last update Tue Mar 28 14:02:30 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "lib/io.h"
#include "my.h"

int	io_init(t_io *io, char *in_path, char *out_path, const int mode)
{
  io->in.line = NULL;
  io->in.row = 0;
  io->in.cursor = 0;
  io->out.buff.capacity = OUT_BUFF_CAPACITY;
  io->out.buff.size = 0;
  io->out.mode = mode;
  io->out.header = NULL;
  if (io_setinput(io, in_path) == -1)
    return (-1);
  io->out.path = (out_path == NULL) ? io_getoutpath(io) : my_strdup(out_path);
  if (io->out.path == NULL ||
      !(io->out.buff.content = malloc(sizeof(char) * io->out.buff.capacity)))
    return (-1);
  my_memset(io->out.buff.content, 0, io->out.buff.capacity);
  return (0);
}

/*
** out.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 21 17:58:12 2017 Thomas ARBONA
** Last update Sun Apr  2 20:46:44 2017 Thomas ARBONA
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/io.h"
#include "lib/endian.h"
#include "my.h"

static int	output_createfile(t_io *io)
{
  if ((io->out.fd = open(io->out.path, O_CREAT | O_TRUNC | O_RDWR,
			 00644)) == -1)
    return (-1);
  free(io->out.path);
  return (0);
}

static int	output_resize(t_io *io, int capacity)
{
  char          *new_buff;

  if (!(new_buff = malloc(capacity)))
    return (-1);
  my_memset(new_buff, 0, capacity);
  my_memcpy(new_buff, io->out.buff.content, io->out.buff.size);
  free(io->out.buff.content);
  io->out.buff.content = new_buff;
  io->out.buff.capacity = capacity;
  return (0);
}

char		*io_getoutpath(t_io *io)
{
  char          *in_name;
  char		*out_path;
  char		**split;

  split = my_strsplit(io->in.path, "/");
  if (my_tablen((void**)split) < 1)
    return (NULL);
  in_name = split[my_tablen((void**)split) - 1];
  if (in_name[my_strlen(in_name) - 1] == 's' &&
      in_name[my_strlen(in_name) - 2] == '.')
    in_name[my_strlen(in_name) - 2] = 0;
  if (!(out_path = malloc(sizeof(char) * my_strlen(in_name) + 5)))
    return (NULL);
  my_strcpy(out_path, in_name);
  my_strcat(out_path, ".cor");
  free_tab((void**)split, -1);
  return (out_path);
}

int	io_outpush(t_io *io, void *src, int len)
{
  int   empty;

  if (io->out.header != NULL)
    io->out.header->prog_size += len;
  empty = io->out.buff.capacity - io->out.buff.size;
  if (empty < len)
    {
      if (output_resize(io, io->out.buff.capacity + len * 2) == -1)
	return (-1);
    }
  my_memcpy(io->out.buff.content + io->out.buff.size, src, len);
  io->out.buff.size += len;
  return (0);
}

int	io_outwrite(t_io *io)
{
  int	status;

  status = 0;
  io->out.header->prog_size = endian_fbigi32(io->out.header->prog_size);
  if (output_createfile(io) == 0)
    {
      if (write(io->out.fd, io->out.header, sizeof(t_header)) == -1 ||
	  write(io->out.fd, io->out.buff.content, io->out.buff.size) == -1)
	status = -1;
    }
  else
    status = -1;
  free(io->out.buff.content);
  close(io->in.fd);
  close(io->out.fd);
  return (status);
}

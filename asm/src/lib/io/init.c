/*
** init.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Apr  2 20:50:09 2017 Thomas ARBONA
** Last update Sun Apr  2 20:53:10 2017 Thomas ARBONA
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib/io.h"
#include "my.h"

static void	handle_backgnl(t_io *io)
{
  char		**split;

  if (g_io_backgnl == 1)
    {
      split = my_strsplit(io->in.line, "\t ");
      vector_push(&io->in.body, split[0] != NULL
		  ? my_strdup(io->in.line) : NULL);
      free_tab((void**)split, -1);
      g_io_backgnl = 0;
    }
}

int     io_initbody(t_io *io)
{
  int   index;
  char  **split;

  index = 0;
  split = NULL;
  io->in.head_row = io->in.row;
  if (vector_init(&io->in.body) == -1)
    return (-1);
  handle_backgnl(io);
  if (io->in.line != NULL)
    free(io->in.line);
  while ((io->in.line = get_next_line(io->in.fd)))
    {
      if (index != 0)
	free_tab((void**)split, -1);
      split = my_strsplit(io->in.line, "\t ");
      vector_push(&io->in.body, split[0] != NULL
		  ? my_strdup(io->in.line) : NULL);
      index += 1;
    }
  if (index > 0 && split != NULL)
    free_tab((void**)split, -1);
  return (0);
}

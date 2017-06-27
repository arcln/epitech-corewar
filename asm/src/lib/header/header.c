/*
** header.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 21 15:33:28 2017 Thomas ARBONA
** Last update Sun Apr  2 20:46:38 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/header.h"
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/helper.h"
#include "lib/endian.h"
#include "my.h"

static char	*extract_string(t_io *io, int n)
{
  int		index;
  t_vec3	curs;

  index = n;
  curs.x = curs.y = -1;
  curs.z = -1;
  while (io->in.line[++index] != 0)
    {
      if (io->in.line[index] == '"')
	(curs.x == -1) ? (curs.x = index) : (curs.y = index);
      else if (my_str_contain(" \t", io->in.line[index]) == -1)
	{
	  if (curs.x == -1 || curs.y != -1)
	    {
	      io->in.col = index;
	      log_syntaxerror(io, SERR_BAD_TOKEN, 1);
	      return (NULL);
	    }
	  curs.z = index;
	}
    }
  io->in.col = curs.z;
  return (curs.x == -1 || curs.y == -1)
    ? log_syntaxerror(io, SERR_BAD_TOKEN, 1), NULL
    : my_strndup(io->in.line + curs.x, curs.y - curs.x + 1);
}

static int	header_setdata(t_io *io, char *data, char *value)
{
  if (value[0] != '\"')
    {
      io->in.col = my_strstr(io->in.line, value) - io->in.line;
      return (-1);
    }
  if (value[my_strlen(value) - 1] != '\"')
    {
      io->in.col = my_strstr(io->in.line, value) - io->in.line
	+ my_strlen(value) - 1;
      return (-1);
    }
  value[my_strlen(value) - 1] = 0;
  my_strcpy(data, value + 1);
  return (0);
}

static int	parse_name(t_io *io, t_header *header)
{
  int		status;
  char		*str;
  int		len;

  status = 0;
  io_getnextline(io);
  if (io->in.line == NULL)
    return (log_syntaxerror(io, SERR_EMPTY_FILE, 0));
  io->in.split = my_strsplit(io->in.line, "\t ");
  len = my_strlen(io->in.split[0]);
  if (!(str = extract_string(io, helper_posinstr(io, 0, len))))
    return (-1);
  if (my_strlen(str) > PROG_NAME_LENGTH + 2)
    status = log_syntaxerror(io, SERR_NAME_TOOLONG, 0);
  else if (my_strcmp(io->in.split[0], ".name") != 0 || io->in.split[1] == NULL)
    status = log_syntaxerror(io, SERR_MISSING_NAME, 0);
  else if (header_setdata(io, header->prog_name, str) == -1)
    status = log_syntaxerror(io, SERR_BAD_TOKEN, 1);
  free_tab((void**)io->in.split, -1);
  free(str);
  return (status);
}

static int	parse_comment(t_io *io, t_header *header)
{
  int		status;
  char		*str;
  int		len;

  status = 0;
  io_getnextline(io);
  if (io->in.line == NULL)
    return (log_syntaxwarning(io, SERR_MISSING_COMMENT, 0));
  io->in.split = my_strsplit(io->in.line, "\t ");
  if (my_strcmp(io->in.split[0], ".comment") != 0 || io->in.split[1] == NULL)
    {
      g_io_backgnl = (io->in.split[1] != NULL) ? 1 : g_io_backgnl;
      log_syntaxwarning(io, SERR_MISSING_COMMENT, 0);
      return (free_tab((void**)io->in.split, -1), status);
    }
  len = my_strlen(io->in.split[0]);
  if (!(str = extract_string(io, helper_posinstr(io, 0, len))))
    return (-1);
  else if (my_strlen(str) > COMMENT_LENGTH + 2)
    status = log_syntaxerror(io, SERR_COMMENT_TOOLONG, 0);
  else if (header_setdata(io, header->comment, str) == -1)
    status = log_syntaxerror(io, SERR_BAD_TOKEN, 1);
  free(str);
  free_tab((void**)io->in.split, -1);
  return (status);
}

int		header_compile(t_io *io, t_header *header)
{
  my_memset(header, 0, sizeof(t_header));
  header->magic = endian_fbigi32(COREWAR_EXEC_MAGIC);
  if (parse_name(io, header) == -1 ||
      parse_comment(io, header) == -1)
    return (-1);
  io->out.header = header;
  return (0);
}

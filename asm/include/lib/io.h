/*
** io.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 21 15:42:20 2017 Thomas ARBONA
** Last update Sun Apr  2 20:46:51 2017 Thomas ARBONA
*/
#ifndef IO_H_
# define IO_H_

# include "lib/header.h"
# include "vector.h"

typedef struct	s_input
{
  int		fd;
  char		*path;
  int		head_row;
  int		row;
  int		col;
  int		cursor;
  char		*line;
  char		**split;
  int		labelised;
  t_vector	body;
}		t_input;

typedef struct	s_buffer
{
  char		*content;
  int		capacity;
  int		size;
}		t_buffer;

typedef struct	s_output
{
  char		*path;
  int		fd;
  t_header	*header;
  t_buffer	buff;
  int		mode;
}		t_output;

typedef struct	s_io
{
  t_input	in;
  t_output	out;
}		t_io;

# ifndef OUT_BUFF_CAPACITY
#  define OUT_BUFF_CAPACITY	10
# endif /* !OUT_BUFF_CAPACITY */

extern int	g_io_backgnl;

int	io_init(t_io *io, char *in_path, char *out_path, const int mode);

int	io_setinput(t_io *io, char *in_path);
int	io_getnextline(t_io *io);

char	*io_getoutpath(t_io *io);
int	io_outpush(t_io *io, void *src, int len);
int	io_outwrite(t_io *io);

int	io_initbody(t_io *io);
void	io_destroybody(t_io *io);
int	io_gnlbody(t_io *io);

#endif /* !IO_H_ */

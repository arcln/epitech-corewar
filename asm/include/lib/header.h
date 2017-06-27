/*
** header.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 21 17:01:13 2017 Thomas ARBONA
** Last update Wed Mar 29 23:14:53 2017 Thomas ARBONA
*/
#ifndef HEADER_H_
# define HEADER_H_

# ifndef PROG_NAME_LENGTH
#  define PROG_NAME_LENGTH       128
# endif /* !PROG_NAME_LENGTH */

# ifndef COMMENT_LENGTH
#  define COMMENT_LENGTH         2048
# endif /* !COMMENT_LENGTH */

# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct	s_vec3
{
  int		x;
  int	        y;
  int		z;
}		t_vec3;

typedef struct  s_header
{
  int           magic;
  char          prog_name[PROG_NAME_LENGTH + 1];
  int           prog_size;
  char          comment[COMMENT_LENGTH + 1];
}               t_header;

typedef struct s_io t_io;

int	header_compile(t_io *io, t_header *header);

#endif /* !HEADER_H_ */

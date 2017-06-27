/*
** precompile.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 21:59:42 2017 Thomas ARBONA
** Last update Sun Apr  2 23:33:13 2017 Thomas ARBONA
*/
#ifndef PRECOMPILE_H_
# define PRECOMPILE_H_

# include <stdlib.h>
# include "lib/op.h"
# include "lib/io.h"
# include "vector.h"

typedef struct	s_label
{
  char		*name;
  int		pos;
}		t_label;

# define _IS_LABCH(c)	('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
# define IS_LABCH(c)	(('0' <= c && c <= '9') || c == '_' || _IS_LABCH(c))

# define REAFFECT(a, b)	free(a); a = b;

typedef struct s_io t_io;

int	body_precompile(t_io *io);
int	body_checkline(t_io *io, int label, int *nbytes);

t_label	*label_create(char *name, int pos);
t_label	*label_get(t_vector *labels, char *label);
int	label_checkargs(t_io *io, t_vector *labels, t_op *op, int shift);
int	is_labeldef(char *str);

void	replace_label(t_io *io, t_vector *labels, int n, int nbytes);
int	replace_commentsplit(t_io *io);
int	replace_comment(t_io *io);

int     precompile_1(t_io *io, t_vector *labels);
int     precompile_2(t_io *io, t_vector *labels);
int     precompile_3(t_io *io, t_vector *labels);

#endif /* !PRECOMPILE_H_ */

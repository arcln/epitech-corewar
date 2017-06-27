/*
** body.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 16:03:11 2017 Thomas ARBONA
** Last update Thu Mar 30 00:43:56 2017 Thomas ARBONA
*/
#ifndef BODY_H_
# define BODY_H_

# include "lib/io.h"
# include "lib/op.h"

# define _ARG_OUTSIZE(t, i)	((t == T_DIR && i) || t == T_IND)
# define ARG_OUTSIZE(t, i)	((t == T_REG) ? 1 : _ARG_OUTSIZE(t, i) ? 2 : 4)

int	body_compile(t_io *io);
void	body_setcodingbyte(t_io *io, t_op *op);

int	arg_gettype(t_io *io, char *arg, int n);

#endif /* !BODY_H_ */

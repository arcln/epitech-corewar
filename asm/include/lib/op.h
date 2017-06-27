/*
** op.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 11:01:56 2017 Thomas ARBONA
** Last update Fri Mar 31 11:51:34 2017 Thomas ARBONA
*/
#ifndef OP_H_
# define OP_H_

# define MAX_ARGS_NB    4

# define COMMENT_CHAR   '#'
# define LABEL_CHAR     ':'
# define DIRECT_CHAR    '%'
# define SEPARATOR_CHAR ','

# define REG_NUMBER     16

# define T_REG          (1 << 0)
# define T_DIR          (1 << 1)
# define T_IND          (1 << 2)
# define T_LAB          (1 << 3)

# define IND_SIZE        2
# define DIR_SIZE        4
# define REG_SIZE        DIR_SIZE

typedef struct  s_op
{
  char          *mnemonique;
  char          nbr_args;
  char          type[MAX_ARGS_NB];
  char          code;
  int           nbr_cycles;
  int		index_arg;
  int		no_codingbyte;
}               t_op;

extern t_op	g_ops[];

t_op	*op_get(char*);

#endif /* !OP_H_ */

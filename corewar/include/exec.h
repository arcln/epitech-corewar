/*
** exec.h for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Mar  1 17:22:07 2017 Arthur Chaloin
** Last update Tue Mar 28 14:36:17 2017 Arthur Chaloin
*/

#ifndef EXEC_H_
# define EXEC_H_

# include "corewar.h"
# include "champion.h"
# include "define.h"

# define SIZE(x) ((x == T_DIR) ? DIR_SIZE : ((x == T_IND) ? IND_SIZE : 1))

typedef struct	s_action
{
  char		token;
  int		cooldown;
  void		(*func)(t_corewar *, t_champion *, t_pc *);
}		t_action;

void	op_live(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_ld(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_st(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_add(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_sub(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_and(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_or(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_xor(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_zjmp(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_ldi(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_sti(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_fork(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_lld(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_lldi(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_lfork(t_corewar *core, t_champion *champion, t_pc *pc);
void	op_aff(t_corewar *core, t_champion *champion, t_pc *pc);

void	read_args(char raw, char args[4]);
int	read_bytes(t_corewar *core, int size, int pos);
void	write_bytes(t_corewar *core, int size, int address, int value);
int	op_read_data(t_corewar *core, t_pc *pc, char args, int cast);

#endif /* !EXEC_H_ */

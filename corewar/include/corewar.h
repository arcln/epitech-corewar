/*
** corewar.h for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Mon Feb 27 19:31:51 2017 Arthur Chaloin
** Last update Sun Apr  2 01:54:33 2017 Arthur Chaloin
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include <stdint.h>
# include "define.h"
# include "champion.h"

# define SYSCALL(x) x

typedef struct	s_corewar
{
  unsigned char	*mem;
  unsigned char	*poss;
  t_champion	*champion;
  t_champion	*winner;
  int		dump_cycle;
  int		cycle;
}		t_corewar;

typedef union	u_transfer
{
  int		nb;
  int16_t	l_nb;
  char		s_nb[4];
}		t_transfer;

int	vm_init(t_corewar *this, const int ac, char *av[]);
void	vm_start(t_corewar *core);
void	core_load_champions(t_corewar *core);
void	core_dump_memory(t_corewar *core) __attribute__((noreturn));
void	core_display_winner(t_corewar *core);

int	pos(int nb);

t_champion	*champion_find(t_corewar *core, int __id);

#endif /* !COREWAR_H_ */

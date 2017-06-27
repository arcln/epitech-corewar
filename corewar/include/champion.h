/*
** champion.h for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Tue Feb 28 10:25:00 2017 Arthur Chaloin
** Last update Fri Mar 31 18:33:43 2017 Arthur Chaloin
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# include "define.h"
# include "vector.h"

typedef struct	s_pc
{
  int		pos;
  int		start;
  int		carry;
  int		state;
  int		reg[REG_NB + 1];
}		t_pc;

typedef struct	s_header
{
  int		magic;
  char		name[PROG_NAME_LEN + 1];
  int		size;
  char		comment[COMMENT_LEN + 1];
}		t_header;

typedef struct		s_champion
{
  t_header		header;
  t_vector		pc;
  int			alive;
  int			last_live;
  int			id;
  char			*name;
  struct s_champion	*next;
}			t_champion;

t_champion	*champion_create(int nb, char *name, int pc);
void		champion_handle_header(t_header *header);
void		champion_destroy(t_champion *this);

#endif /* !CHAMPION_H_ */

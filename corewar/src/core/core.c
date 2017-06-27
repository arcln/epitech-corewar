/*
** core.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Tue Feb 28 10:40:02 2017 Arthur Chaloin
** Last update Sun Apr  2 01:57:07 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "corewar.h"
#include "champion.h"
#include "error.h"
#include "my.h"

void		core_display_winner(t_corewar *core)
{
  int		min;
  t_champion	*cursor;
  t_champion	*winner;

  min = 2147483647;
  cursor = core->champion;
  while (cursor)
    {
      if (cursor->last_live < min)
	{
	  winner = cursor;
	  min = cursor->last_live;
	}
      cursor = cursor->next;
    }
  if (winner)
    {
      my_printf("The player %d(%s) has won.\n",
		winner->id, winner->header.name);
      core->winner = winner;
    }
}

void		core_init_memory(t_corewar *core)
{
  int		index;

  index = -1;
  if (!(core->mem = malloc(sizeof(char) * MEM_SIZE)) ||
      !(core->poss = malloc(sizeof(char) * MEM_SIZE)))
    throw_error("Can't perform malloc\n");
  while (++index < MEM_SIZE)
    {
      core->mem[index] = 0;
      core->poss[index] = 0;
    }
  core->cycle = 0;
  core->winner = NULL;
}

static void	core_add_champion(t_corewar *this, char *name,
				  int force_nb, int pc)
{
  t_champion	*new;
  t_champion	*cursor;
  static int	champ_nb = 1;

  if (force_nb < 0)
    new = champion_create(champ_nb++, name, pc);
  else
    new = champion_create(force_nb, name, pc);
  cursor = this->champion;
  if (!cursor)
    this->champion = new;
  else
    {
      if (cursor->id == new->id)
        throw_error("Invalid champion numbers.\n");
      while (cursor->next)
	{
	  if (cursor->id == new->id)
	    throw_error("Invalid champion numbers.\n");
	  cursor = cursor->next;
	}
      cursor->next = new;
    }
}

static int	handle_param(t_corewar *this, char *av[],
			     int *index, int params[2])
{
  if (av[*index][0] != '-')
    {
      core_add_champion(this, av[*index], params[1], params[0]);
      params[0] = params[1] = -1;
    }
  else if (!my_strcmp(av[*index], "-dump") && av[*index + 1])
    this->dump_cycle = my_getnbr(av[(*index)++ + 1]);
  else if (!my_strcmp(av[*index], "-a") && av[*index + 1])
    *index += (params[0] = my_getnbr(av[*index + 1])) != 0;
  else if (!my_strcmp(av[*index], "-n") && av[*index + 1])
    *index += (params[1] = my_getnbr(av[*index + 1])) != 0;
  else if (!my_strcmp(av[*index], "-h"))
    return (display_help());
  else
    throw_error(INVALID_ARG_ERR);
  return (0);
}

int	vm_init(t_corewar *this, const int ac, char *av[])
{
  int	index;
  int	params[2];

  index = 0;
  params[0] = params[1] = -1;
  this->dump_cycle = -1;
  this->champion = NULL;
  while (++index < ac)
    {
      if (handle_param(this, av, &index, params))
	return (EXIT_FAILURE);
    }
  if (params[0] >= 0 || params[1] >= 0)
    throw_error(INVALID_ARG_ERR);
  core_init_memory(this);
  core_load_champions(this);
  return (EXIT_SUCCESS);
}

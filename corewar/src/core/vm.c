/*
** vm.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Mar  1 17:20:55 2017 Arthur Chaloin
** Last update Fri Apr  7 14:49:19 2017 Arthur Chaloin
*/
#include <unistd.h>
#include "define.h"
#include "corewar.h"
#include "champion.h"
#include "exec.h"
#include "my.h"

t_action	call[] = {
  {1, 10, &op_live},
  {2, 5, &op_ld},
  {3, 5, &op_st},
  {4, 10, &op_add},
  {5, 10, &op_sub},
  {6, 6, &op_and},
  {7, 6, &op_or},
  {8, 6, &op_xor},
  {9, 20, &op_zjmp},
  {10, 25, &op_ldi},
  {11, 25, &op_sti},
  {12, 800, &op_fork},
  {13, 10, &op_lld},
  {14, 50, &op_lldi},
  {15, 1000, &op_lfork},
  {16, 2, &op_aff},
  {0, 0, NULL}
};

static int	vm_alive(t_corewar *core, int cycles_to_die)
{
  int		alives;
  t_champion	*actual;

  alives = 0;
  actual = core->champion;
  while (actual)
    {
      if (actual->last_live >= cycles_to_die)
	actual->alive = 0;
      else
	alives++;
      actual = actual->next;
    }
  return ((alives > 1));
}

static void	vm_start_cooldown(t_corewar *core, t_pc *pc)
{
  int		index;

  index = -1;
  while (call[++index].token && call[index].token != core->mem[pos(pc->pos)]);
  if (!call[index].token)
    {
      (pc->pos)++;
      return;
    }
  pc->state = call[index].cooldown - 1;
}

static int	vm_execute(t_corewar *core, t_champion *champion, t_pc *pc)
{
  int		index;

  index = -1;
  while (call[++index].token && call[index].token != core->mem[pc->pos]);
  if (call[index].token)
    call[index].func(core, champion, pc);
  (pc->pos)++;
  pc->state = -1;
  return ((call[index].token == 1));
}

static int	vm_play_turn(t_corewar *core, t_champion *champion)
{
  int		index;
  int		champ_live;
  t_pc		*pc;

  index = -1;
  champ_live = 0;
  while (++index < vector_getsize(&(champion->pc)))
    {
      pc = vector_get(&(champion->pc), index, t_pc);
      pc->pos = pos(pc->pos);
      if (pc->state < 0)
	vm_start_cooldown(core, pc);
      else if (!pc->state)
	champ_live += vm_execute(core, champion, pc);
      else
	(pc->state)--;
    }
  return (champ_live);
}

static int	vm_play_cycle(t_corewar *core)
{
  int		nb_lives;
  t_champion	*champion;

  nb_lives = 0;
  champion = core->champion;
  while (champion)
    {
      if (champion->alive)
	{
	  nb_lives += (vm_play_turn(core, champion) != 0);
          (champion->last_live)++;
	}
      champion = champion->next;
    }
  return (nb_lives);
}

void		vm_start(t_corewar *core)
{
  int		cycles_to_die;
  int		nbr_live;

  cycles_to_die = CYCLE_TO_DIE;
  nbr_live = 0;
  while (vm_alive(core, cycles_to_die))
    {
      if (core->cycle == core->dump_cycle)
	core_dump_memory(core);
      nbr_live += vm_play_cycle(core);
      if (nbr_live >= NBR_LIVE)
	{
	  cycles_to_die -= CYCLE_DELTA;
	  nbr_live = 0;
	}
      (core->cycle)++;
      usleep(4200);
    }
  core_display_winner(core);
}

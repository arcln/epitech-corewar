/*
** champion.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Tue Feb 28 10:31:42 2017 Arthur Chaloin
** Last update Thu Mar 30 01:27:12 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "champion.h"
#include "vector.h"
#include "my.h"

t_champion	*champion_create(int __id, char *__name, int __pc)
{
  int		index;
  t_champion	*this;
  t_pc		*pc;

  index = -1;
  if (!(this = malloc(sizeof(t_champion))) ||
      !(pc = malloc(sizeof(t_pc))))
    return (NULL);
  this->alive = 1;
  this->id = __id;
  this->name = __name;
  this->last_live = 0;
  while (++index < REG_NB + 1)
    pc->reg[index] = 0;
  pc->reg[1] = __id;
  pc->pos = __pc;
  pc->carry = 0;
  pc->state = -1;
  vector_init(&(this->pc));
  vector_push(&(this->pc), pc);
  this->next = NULL;
  return (this);
}

t_champion	*champion_find(t_corewar *core, int __id)
{
  t_champion	*cursor;

  cursor = core->champion;
  while (cursor)
    {
      if (cursor->id == __id)
	return (cursor);
      cursor = cursor->next;
    }
  return (NULL);
}

void		champion_handle_header(t_header *header)
{
  char		tmp;
  char		*raw;

  if (header->magic != COREWAR_EXEC_MAGIC)
    {
      raw = (char *)&(header->size);
      tmp = raw[3];
      raw[3] = raw[0];
      raw[0] = tmp;
      tmp = raw[2];
      raw[2] = raw[1];
      raw[1] = tmp;
    }
}

void		champion_destroy(t_champion *this)
{
  vector_free(&(this->pc));
  free(this);
}

/*
** placement.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/champion/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Feb 28 18:36:48 2017 Arthur Chaloin
** Last update Sun Apr  2 01:21:06 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "define.h"
#include "corewar.h"
#include "champion.h"
#include "error.h"

static void	core_write_champion(t_corewar *core, t_champion *champ,
				    int address)
{
  int		fd;
  int		index;
  int		bytes;
  unsigned char	buff[MEM_SIZE];

  if ((fd = open(champ->name, O_RDONLY)) < 0 ||
      (read(fd, &(champ->header), sizeof(t_header)) < 0))
    throw_error("Failed to open file.\n");
  champion_handle_header(&(champ->header));
  if (champ->header.size >= MAX_CHAMP_SIZE)
    throw_error("Invalid champion.\n");
  if ((bytes = read(fd, buff, champ->header.size)) < 0)
    throw_error("Failed to read file.\n");
  if (bytes != champ->header.size)
    throw_error("Invalid champion.\n");
  index = -1;
  while (++index < champ->header.size)
    {
      if (core->mem[pos(address + index)])
	throw_error("Bad champion placement.\n");
      core->mem[pos(address + index)] = buff[index];
      core->poss[pos(address + index)] = champ->id;
    }
  if ((vector_get(&(champ->pc), 0, t_pc))->pos == -1)
    (vector_get(&(champ->pc), 0, t_pc))->pos = address;
}

void		core_load_champions(t_corewar *core)
{
  int		count;
  int		champs_nb;
  t_champion	*cursor;

  cursor = core->champion;
  champs_nb = 0;
  while (cursor)
    {
      champs_nb++;
      cursor = cursor->next;
    }
  count = 0;
  cursor = core->champion;
  while (cursor)
    {
      core_write_champion(core, cursor,
			  (((vector_get(&(cursor->pc), 0, t_pc))->pos == -1) ?
			   (MEM_SIZE / champs_nb) * count :
			   (vector_get(&(cursor->pc), 0, t_pc))->pos));
      cursor = cursor->next;
      count++;
    }
}

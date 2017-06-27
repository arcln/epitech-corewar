/*
** utils.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Feb 28 11:59:05 2017 Arthur Chaloin
** Last update Thu Mar  2 19:49:25 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "define.h"
#include "my.h"

int	pos(int nb)
{
  while (nb >= MEM_SIZE)
    nb -= MEM_SIZE;
  while (nb < 0)
    nb += MEM_SIZE;
  return (nb);
}

void	throw_error(char *err)
{
  write(2, err, my_strlen(err));
  exit(84);
}

int		display_help()
{
  int		fd;
  char		buffer[1024];

  if ((fd = open("README.md", O_RDONLY)) == -1)
    return (1);
  write(1, buffer, read(fd, buffer, 1024));
  return (1);
}

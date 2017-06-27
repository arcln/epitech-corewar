/*
** free_tab.c for my in /home/arbona/libs/my/src
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Mar 25 21:39:43 2017 Thomas ARBONA
** Last update Sat Mar 25 22:35:04 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void	free_tab(void **tab, int len)
{
  int	index;

  index = 0;
  if (len == -1)
    len = my_tablen(tab);
  while (index < len)
    {
      if (tab[index] != NULL)
	free(tab[index]);
      index += 1;
    }
  free(tab);
}

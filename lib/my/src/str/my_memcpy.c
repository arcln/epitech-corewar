/*
** my_memcpy.c for my in /home/arbona/libs/my/src
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Mar 25 21:43:00 2017 Thomas ARBONA
** Last update Sat Mar 25 21:46:02 2017 Thomas ARBONA
*/
#include <unistd.h>

void	*my_memcpy(void *dest, void *src, int len)
{
  int	index;

  if (dest == NULL || src == NULL)
    return (NULL);
  index = 0;
  while (index < len)
    {
      ((char*)dest)[index] = ((char*)src)[index];
      index += 1;
    }
  return (dest);
}

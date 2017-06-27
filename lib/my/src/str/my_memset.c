/*
** my_memset.c for my in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 19:45:19 2016 Thomas ARBONA
** Last update Sun Mar 26 03:14:01 2017 Thomas ARBONA
*/

// line 21 for my_printf
void	*my_memset(void *s, int c, int len)
{
  int	index;

  index = 0;
  while (index < len)
    {
      ((char*)s)[index] = c;
      index += 1;
    }
  ((char*)s)[len - 1] = 0;
  return (s);
}

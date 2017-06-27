/*
** my_strsplit.c for my in /home/arbona/test
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Mar 25 20:48:46 2017 Thomas ARBONA
** Last update Mon Mar 27 21:29:54 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

static int	count_tokens(char *str, char *delim)
{
  int		index;
  int		count;

  index = 0;
  count = 0;
  while (str[index] != 0)
    {
      if (my_str_contain(delim, str[index]) != -1 &&
	  index != 0 && my_str_contain(delim, str[index - 1]) == -1)
	count += 1;
      index += 1;
    }
  if (index != 0 && my_str_contain(delim, str[index - 1]) == -1)
    count += 1;
  return (count);
}

char	**my_strsplit(char *str, char *delim)
{
  int	count;
  int	index;
  char	**tokens;
  char	*_str;

  _str = my_strdup(str);
  count = count_tokens(_str, delim);
  if (!(tokens = malloc(sizeof(char*) * (count + 1))))
    return (NULL);
  tokens[count] = NULL;
  if (count != 0)
    {
      tokens[0] = my_strdup(my_strtok(_str, delim));
      index = 1;
      while (index < count)
	{
	  tokens[index] = my_strdup(my_strtok(NULL, delim));
	  index += 1;
	}
    }
  free(_str);
  return (tokens);
}

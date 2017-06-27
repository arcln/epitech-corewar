/*
** my_strtok.c for my in /home/arbona/test
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Mar 25 20:40:36 2017 Thomas ARBONA
** Last update Sat Mar 25 21:15:53 2017 Thomas ARBONA
*/
#include <unistd.h>

int	my_str_contain(char*, char);

char            *my_strtok(char *str, char *delim)
{
  static char   *buff;
  char          *tok;
  int           index;

  if (str != NULL)
    buff = str;
  if (buff == NULL || buff[0] == 0)
    return (NULL);
  tok = buff;
  index = -1;
  while (tok[++index] != 0)
    {
      if (my_str_contain(delim, tok[index]) != -1)
	{
	  if (*tok != tok[index])
	    break;
	  tok = (buff += 1);
	  index -= 1;
	}
    }
  buff += index + 1;
  if (tok[index] == 0)
    buff = NULL;
  tok[index] = 0;
  return (tok);
}

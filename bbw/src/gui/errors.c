/*
** win_err.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 21 23:19:29 2017 Paul Laffitte
** Last update Sat Mar 25 18:10:20 2017 Paul Laffitte
*/

#include <gtk/gtk.h>
#include <unistd.h>
#include <my.h>

int	flush_err(GError **err)
{
  if (*err)
    {
      write(2, (*err)->message, my_strlen((*err)->message));
      write(2, "\n", 1);
      g_error_free(*err);
      *err = NULL;
      return (84);
    }
  return (0);
}

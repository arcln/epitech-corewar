/*
** main.c for g_corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Mar 20 17:03:46 2017 Paul Laffitte
** Last update Tue Apr 25 11:24:14 2017 Arthur Chaloin
*/
#include <gtk/gtk.h>
#include <string.h>
#include <pthread.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "define.h"
#include "corewar.h"
#include "gui/window.h"
#include "bbw.h"
#include "gl.h"

int		g_done = 0;
int		g_running = -1;

t_corewar	*g_corewar;
t_music		*g_music;
t_list		*g_champions = NULL;
pthread_t	g_vm_thread;

static char	**get_av()
{
  int		index;
  t_list	*cursor;
  char		**av;

  index = 1;
  cursor = g_champions;
  if (!(av = malloc(sizeof(char *) * (list_len(&g_champions) + 2))))
    exit(84);
  av[0] = "./bbw";
  while (cursor)
    {
      av[index] = (char *)cursor->element;
      cursor = cursor->next;
      index++;
    }
  av[index] = NULL;
  return (av);
}

static void	*vm_launch(__attribute__((unused))void *argp)
{
  int		index;
  char		**av;

  index = -1;
  while (g_running != 1);
  start_music();
  av = get_av();
  vm_init(g_corewar, my_tablen((void *)av), av);
  g_running = 2;
  while (++index < 1000)
    {
      g_eye[0] = EYE_X;
      g_eye[1] = EYE_Y + index;
      g_eye[2] = EYE_Z;
      if (g_corewar->cycle == -1)
	exit(0);
      usleep(4200);
    }
  vm_start(g_corewar);
  g_done = 1;
  return (NULL);
}

int	main(int ac, char *av[])
{
  t_music	music_base;
  t_corewar	core;

  g_music = &music_base;
  g_corewar = &core;
  gtk_init(&ac, &av);
  pthread_create(&g_vm_thread, NULL, &vm_launch, NULL);
  pthread_detach(g_vm_thread);
  open_window();
  return (0);
}

/*
** main.c for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/debug/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 28 17:29:31 2017 Arthur Chaloin
** Last update Sun Apr  2 01:19:11 2017 Arthur Chaloin
*/
#include <string.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include <SFML/Graphics.h>
#include "define.h"
#include "corewar.h"
#include "video.h"

int	done = 0;

typedef struct {
  t_corewar	*core;
  t_video	*video;
}		t_args;

static void	video_push(t_corewar *core, t_video *video, int index,
			   sfColor color[4])
{
  int		index2;
  t_champion	*tmp;
  t_pc		*pc;

  tmp = core->champion;
  while (tmp)
    {
      index2 = -1;
      while (++index2 < vector_getsize(&tmp->pc))
	{
	  pc = vector_get(&tmp->pc, index2, t_pc);
	  if (index == pos(pc->pos))
	    {
	      video->fb->pixels[index * 4] = color[core->poss[index]].r;
	      video->fb->pixels[index * 4 + 1] = color[core->poss[index]].g;
	      video->fb->pixels[index * 4 + 2] = color[core->poss[index]].b;
	      video->fb->pixels[index * 4 + 3] = 0;
	    }
	}
      tmp = tmp->next;
    }
}

static void	video_update(t_video *video, t_corewar *core)
{
  int		index;
  sfColor	color[4];

  index = -1;
  color[0] = (sfColor){255, 255, 255, 255};
  color[1] = (sfColor){0, 255, 0, 255};
  color[2] = (sfColor){0, 0, 255, 255};
  color[3] = (sfColor){255, 255, 0, 255};
  while (++index < MEM_SIZE)
    {
      video->fb->pixels[index * 4] = color[core->poss[index]].r;
      video->fb->pixels[index * 4 + 1] = color[core->poss[index]].g;
      video->fb->pixels[index * 4 + 2] = color[core->poss[index]].b;
      video->fb->pixels[index * 4 + 3] = color[core->poss[index]].a;
      video_push(core, video, index, color);
    }
}

static void	*vm_launch(void *argp)
{
  t_args	*args;

  args = (t_args *)argp;
  vm_start(args->core);
  done = 1;
  return (NULL);
}

int	main(const int ac, char *av[])
{
  t_corewar	core;
  t_video	video;
  t_args	args;
  pthread_t	id;

  if (ac < 2 || vm_init(&core, ac, av))
    return (84);
  XInitThreads();
  video_init(&video);
  args.core = &core;
  args.video = &video;
  pthread_create(&id, NULL, &vm_launch, (void *)&args);
  pthread_detach(id);
  while (!done)
    {
      memset(video.fb->pixels, 42, MEM_SIZE * 4);
      sfRenderWindow_clear(video.window, sfBlack);
      video_update(&video, &core);
      sfTexture_updateFromPixels(video.texture, video.fb->pixels,
				 video.mode.width, video.mode.height, 0, 0);
      sfRenderWindow_drawSprite(video.window, video.sprite, NULL);
      sfRenderWindow_display(video.window);
    }
  return (0);
}

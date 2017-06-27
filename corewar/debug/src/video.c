/*
** video.c for wolf3d in /home/arthur/Documents/B1-C_Graph_Prog/wolf3d/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Dec 12 09:26:23 2016 Arthur Chaloin
** Last update Tue Mar 28 17:39:12 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "video.h"

static t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			cursor;
  t_my_framebuffer	*buffer;

  if (!(buffer = malloc(sizeof(t_my_framebuffer))) ||
      !(buffer->pixels = malloc(sizeof(sfUint8) * (width * height * 4))))
    return (NULL);
  buffer->width = width;
  buffer->height = height;
  cursor = 0;
  while (cursor < width * height * 4)
    {
      buffer->pixels[cursor] = 0;
      cursor++;
    }
  return (buffer);
}

void		video_init(t_video *video)
{
  video->mode.width = WIDTH;
  video->mode.height = HEIGHT;
  video->mode.bitsPerPixel = 32;
  video->window = sfRenderWindow_create(video->mode, "corewar", V_MODE, NULL);
  video->fb = my_framebuffer_create(video->mode.width, video->mode.height);
  video->texture = sfTexture_create(WIDTH, HEIGHT);
  video->sprite = sfSprite_create();
  sfSprite_setTexture(video->sprite, video->texture, sfTrue);
  sfWindow_setSize((sfWindow *)video->window, (sfVector2u){1000, 1000});
}

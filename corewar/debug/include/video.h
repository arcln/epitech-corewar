/*
** video.h for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar/debug/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 28 17:18:30 2017 Arthur Chaloin
** Last update Tue Mar 28 17:24:04 2017 Arthur Chaloin
*/

#ifndef VIDEO_H_
# define VIDEO_H_

# define WIDTH	64
# define HEIGHT	64
# define V_MODE	sfResize | sfClose

# include <SFML/Graphics.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_video_data
{
  t_my_framebuffer	*fb;
  sfRenderWindow	*window;
  sfVideoMode		mode;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
}			t_video;

void		video_init(t_video *video);

#endif /* !VIDEO_H_ */

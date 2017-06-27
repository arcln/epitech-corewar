/*
** load_shader.c for g_corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Mar 27 17:41:17 2017 Paul Laffitte
** Last update Sun Apr  2 18:19:31 2017 Paul Laffitte
*/

#include <stdlib.h>
#include "gl.h"
#include "math_gl.h"
#include "bbw.h"

void	move_to(float position[3], float smooth)
{
  smooth *= smooth;
  g_eye[0] = (smooth * g_eye[0] + position[0]) / (smooth + 1);
  g_eye[1] = (smooth * g_eye[1] + position[1]) / (smooth + 1);
  g_eye[2] = (smooth * g_eye[2] + position[2]) / (smooth + 1);
}

void	turn_around(GtkBuilder *builder)
{
  GtkWidget	*circular_rbtn;
  float		dest[3];

  circular_rbtn = GTK_WIDGET(gtk_builder_get_object(builder, "circular_rbtn"));
  if (g_corewar->cycle != 0
      && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(circular_rbtn)))
    {
      dest[0] = EYE_X + cos(g_eye[3]) * 50;
      dest[1] = g_eye[1];
      dest[2] = EYE_Z + sin(g_eye[3]) * 50;
      move_to(dest, 280);
      g_eye[3] += 0.000015;
    }
}

void	random_movement(GtkBuilder *builder)
{
  GtkWidget	*rand_rbtn;
  static float	dest[3] = {0};

  rand_rbtn = GTK_WIDGET(gtk_builder_get_object(builder, "rand_rbtn"));
  if (g_corewar->cycle != 0
      && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rand_rbtn)))
    {
      if (FLOAT_APPROX(g_eye[0] - dest[0], 120)
	  && FLOAT_APPROX(g_eye[1] - dest[1], 120)
	  && FLOAT_APPROX(g_eye[2] - dest[2], 120))
	{
	  dest[0] = rand() % 800 - 400;
	  dest[1] = rand() % 800 - 400;
	  dest[2] = rand() % 800 - 400;
	}
      move_to(dest, 400);
    }
}

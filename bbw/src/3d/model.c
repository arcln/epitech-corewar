/*
** model.c for g_corewar in /home/arthur/B2/CPE/CPE_2016_corewar/bbw/src/3d/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Mar 29 21:43:17 2017 Arthur Chaloin
** Last update Tue Apr 25 11:10:57 2017 Arthur Chaloin
*/
#include <GL/glew.h>
#include "gl.h"
#include "math_gl.h"
#include "define.h"
#include "corewar.h"
#include "bbw.h"

const float	colors[][3] = {
  {0.21, 0.21, 0.21},
  {0.84, 0.10, 0.10},
  {0.10, 0.84, 0.10},
  {0.10, 0.10, 0.84},
  {0.90, 0.10, 0.84},
};

static void	push_data(float transform[4][4], int pos, float moy)
{
  glBindBuffer(GL_ARRAY_BUFFER, g_gl.colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data),
	       g_color_buffer_data, GL_STATIC_DRAW);
  transform[3][0] = sqrt(MEM_SIZE) - ((float)((pos % (int)sqrt(MEM_SIZE)) -
				      (sqrt(MEM_SIZE) / 2.)) /
			 sqrt(MEM_SIZE) * 200.) - sqrt(MEM_SIZE);
  transform[3][1] = -30 + (10 * moy);
  transform[3][2] = sqrt(MEM_SIZE) - ((float)((pos / (int)sqrt(MEM_SIZE)) -
				      (sqrt(MEM_SIZE) / 2.)) /
			 sqrt(MEM_SIZE) * 200.);
  mat_product(g_gl.mvp, transform);
}

void		mat_model(int pos, float moy)
{
  int		index;
  float		transform[4][4];
  static float	progress[MEM_SIZE] = {-1};
  static float	last[MEM_SIZE] = {-1};

  moy = (moy > 1.65) ? 1.65 : moy;
  moy = -(1 / (moy / 2.2)) / 1.8 + 2;
  index = 0;
  if (last[pos] < 0 || last[pos] != g_corewar->poss[pos])
    {
      last[pos] = g_corewar->poss[pos];
      progress[pos] = 1.;
    }
  progress[pos] = (progress[pos] <= 0) ? 0 : progress[pos] - 0.05;
  while (index < 3 * 36)
    {
      g_color_buffer_data[index] = colors[g_corewar->poss[pos]][0] +
	  ((1 - colors[g_corewar->poss[pos]][0]) * progress[pos]);
      g_color_buffer_data[index + 1] = colors[g_corewar->poss[pos]][1] +
	  ((1 - colors[g_corewar->poss[pos]][1]) * progress[pos]);
      g_color_buffer_data[index + 2] = colors[g_corewar->poss[pos]][2] +
	  ((1 - colors[g_corewar->poss[pos]][2]) * progress[pos]);
      index += 3;
    }
  push_data(transform, pos, moy);
}

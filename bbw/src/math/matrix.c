/*
** matrix.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/math/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Mar 29 10:42:35 2017 Paul Laffitte
** Last update Wed Mar 29 19:00:16 2017 Paul Laffitte
*/

#include "math_gl.h"

void		mat_cpy(float src[4][4], float buffer[4][4])
{
  buffer[0][0] = src[0][0];
  buffer[0][1] = src[0][1];
  buffer[0][2] = src[0][2];
  buffer[0][3] = src[0][3];
  buffer[1][0] = src[1][0];
  buffer[1][1] = src[1][1];
  buffer[1][2] = src[1][2];
  buffer[1][3] = src[1][3];
  buffer[2][0] = src[2][0];
  buffer[2][1] = src[2][1];
  buffer[2][2] = src[2][2];
  buffer[2][3] = src[2][3];
  buffer[3][0] = src[3][0];
  buffer[3][1] = src[3][1];
  buffer[3][2] = src[3][2];
  buffer[3][3] = src[3][3];
}

void		mat_transpose(float matrix[4][4])
{
  float		tmp[4][4];

  mat_cpy(matrix, tmp);
  matrix[0][0] = tmp[0][0];
  matrix[0][1] = tmp[1][0];
  matrix[0][2] = tmp[2][0];
  matrix[0][3] = tmp[3][0];
  matrix[1][0] = tmp[0][1];
  matrix[1][1] = tmp[1][1];
  matrix[1][2] = tmp[2][1];
  matrix[1][3] = tmp[3][1];
  matrix[2][0] = tmp[0][2];
  matrix[2][1] = tmp[1][2];
  matrix[2][2] = tmp[2][2];
  matrix[2][3] = tmp[3][2];
  matrix[3][0] = tmp[0][3];
  matrix[3][1] = tmp[1][3];
  matrix[3][2] = tmp[2][3];
  matrix[3][3] = tmp[3][3];
}

static void	mat_get_line(float matrix[4][4],
			     int line, float buffer[4])
{
  buffer[0] = matrix[0][line];
  buffer[1] = matrix[1][line];
  buffer[2] = matrix[2][line];
  buffer[3] = matrix[3][line];
}

void		mat_product(float m1[4][4], float m2[4][4])
{
  int		x;
  int		y;
  float		vector[4];
  float		tmp[4][4];

  mat_cpy(m1, tmp);
  y = 0;
  while (y < 4)
    {
      x = 0;
      while (x < 4)
	{
	  mat_get_line(tmp, y, vector);
	  m1[x][y] = VEC_DOT4(vector, m2[x]);
	  x++;
	}
      y++;
    }
}

/*
** vector.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/math/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 28 18:15:41 2017 Paul Laffitte
** Last update Wed Mar 29 11:21:18 2017 Paul Laffitte
*/

#include <math.h>

void	vec_normalize(float vec[3])
{
  float	norm;

  if ((norm = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2])) == 0)
    return ;
  vec[0] = vec[0] / norm;
  vec[1] = vec[1] / norm;
  vec[2] = vec[2] / norm;
}

void	vec_cross(float v1[3], float v2[3], float buffer[3])
{
  buffer[0] = v1[1] * v2[2] - v1[2] * v2[1];
  buffer[1] = v1[2] * v2[0] - v1[0] * v2[2];
  buffer[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void	vec_sub(float v1[3], float v2[3], float buffer[3])
{
  buffer[0] = v1[0] - v2[0];
  buffer[1] = v1[1] - v2[1];
  buffer[2] = v1[2] - v2[2];
}

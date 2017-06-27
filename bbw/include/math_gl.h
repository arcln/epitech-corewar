/*
** math_gl.h for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 28 18:17:22 2017 Paul Laffitte
** Last update Thu Mar 30 23:28:56 2017 Paul Laffitte
*/

#ifndef MATH_GL_H_
# define MATH_GL_H_

# include <math.h>

#ifndef ABS
# define ABS(nb) (nb) > 0 ? (nb) : -(nb)
#endif /* !ABS */

#ifndef RAD
# define RAD(angle) ((angle) * M_PI / 180.f)
#endif /* !RAD */

#ifndef VEC_DOT3
# define VEC_DOT3(v1, v2) (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2])
#endif /* !NEAR */

#ifndef VEC_DOT4
# define VEC_DOT4(v1, v2) (VEC_DOT3(v1, v2) + v1[3] * v2[3])
#endif /* !NEAR */

# ifndef FLOAT_APPROX
#  define FLOAT_APPROX(flt, prec) (ABS(flt) < prec)
# endif /* !FLOAT_APPROX */

void	vec_normalize(float vec[3]);
void	vec_cross(float v1[3], float v2[3], float buffer[3]);
void	vec_sub(float v1[3], float v2[3], float buffer[3]);

void	mat_print(char *name, float matrix[4][4]);
void	mat_cpy(float src[4][4], float buffer[4][4]);
void	mat_transpose(float matrix[4][4]);
void	mat_product(float m1[4][4], float m2[4][4]);

#endif /* !MATH_GL_H_ */

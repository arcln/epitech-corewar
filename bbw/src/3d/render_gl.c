/*
** render_g_gl.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Mar 26 21:52:20 2017 Paul Laffitte
** Last update Tue Apr 25 11:10:51 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include "gl.h"
#include "math_gl.h"
#include "define.h"
#include "bbw.h"

float	g_eye[4];

static void	mat_perspective(float ratio)
{
  memset(g_gl.mvp, 0, sizeof(g_gl.mvp));
  g_gl.mvp[0][0] = 1 / (ratio * tanf(g_gl.fov / 2));
  g_gl.mvp[1][1] = 1 / tanf(g_gl.fov / 2);
  g_gl.mvp[2][2] = -((FAR + NEAR) / (FAR - NEAR));
  g_gl.mvp[2][3] = -1;
  g_gl.mvp[3][2] = -((2 * FAR * NEAR) / (FAR - NEAR));
  g_gl.mvp[0][0] = 1 / (ratio * tan(g_gl.fov / 2));
  g_gl.mvp[1][1] = 1 / tanf(g_gl.fov / 2);
}

static void	compute_mat(float view[4][4], float coord[3][3])
{
  view[0][0] = coord[0][0];
  view[1][0] = coord[0][1];
  view[2][0] = coord[0][2];
  view[3][0] = -VEC_DOT3(coord[0], g_eye);
  view[0][1] = coord[1][0];
  view[1][1] = coord[1][1];
  view[2][1] = coord[1][2];
  view[3][1] = -VEC_DOT3(coord[1], g_eye);
  view[0][2] = coord[2][0];
  view[1][2] = coord[2][1];
  view[2][2] = coord[2][2];
  view[3][2] = -VEC_DOT3(coord[2], g_eye);
  view[0][3] = 0;
  view[1][3] = 0;
  view[2][3] = 0;
  view[3][3] = 1;
}

static void	mat_look_at(float center[3], float up[3])
{
  float		view[4][4];
  float		coord[3][3];

  vec_sub(g_eye, center, coord[2]);
  vec_normalize(coord[2]);
  coord[1][0] = up[0];
  coord[1][1] = up[1];
  coord[1][2] = up[2];
  vec_cross(up, coord[2], coord[0]);
  vec_normalize(coord[0]);
  vec_cross(coord[2], coord[0], coord[1]);
  compute_mat(view, coord);
  mat_product(g_gl.mvp, view);
}

static void	handle_cube(GtkBuilder *builder, int index)
{
  float		moy;
  static float	center[3] = {EYE_X, 0, 50};
  static float	up[3] = {0, 1, 0};

  turn_around(builder);
  random_movement(builder);
  moy = (get_spectrum(index) / 3) + 1;
  mat_perspective(1820. / 1080.);
  mat_look_at(center, up);
  mat_model(index, moy);
  glUniformMatrix4fv(g_gl.matrix_id, 1, GL_FALSE, (float *)g_gl.mvp);
  glBindBuffer(GL_ARRAY_BUFFER, g_gl.vertex_buffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glBindBuffer(GL_ARRAY_BUFFER, g_gl.colorbuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
}

int		render_gl(GtkGLArea *gl_area,
			  __attribute__((unused))GdkEvent *event,
			  GtkBuilder *builder)
{
  int		index;

  index = -1;
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(g_gl.shader);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  while (++index < MEM_SIZE && (g_running == 2 || g_running == 0))
    handle_cube(builder, index);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  gtk_widget_queue_draw(GTK_WIDGET(gl_area));
  while (gtk_events_pending())
    gtk_main_iteration();
  if (g_corewar->winner && g_corewar->cycle > 0)
    show_winner();
  return (TRUE);
}

/*
** gl.h for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/include/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Mar 26 21:53:38 2017 Paul Laffitte
** Last update Tue Apr 25 11:09:57 2017 Arthur Chaloin
*/

#ifndef GL_H_
# define GL_H_

#ifndef NEAR
# define NEAR 0.1
#endif /* !NEAR */

#ifndef FAR
# define FAR 10000.0
#endif /* !FAR */

#ifndef EYE_X
# define EYE_X 1.9
#endif /* !EYE_X */

#ifndef EYE_Y
# define EYE_Y -930.0
#endif /* !EYE_Y */

#ifndef EYE_Z
# define EYE_Z -160.0
#endif /* !EYE_Z */

# include <gtk/gtk.h>
# include <OpenGL/gl.h>

typedef struct	s_gl
{
  GLuint	vertex_buffer;
  GLuint	shader;
  GLuint	matrix_id;
  GLuint	colorbuffer;
  float		mvp[4][4];
  float		fov;
}		t_gl;

extern t_gl	g_gl;
extern GLfloat	g_color_buffer_data[3 * 36];
extern float	g_eye[4];

int		init_gl(GtkGLArea *gl_area);
int		render_gl(GtkGLArea *gl_area,
			  GdkEvent *event, GtkBuilder *builder);

GLuint		load_shaders(const char *vertex_filename,
			     const char *fragment_filename);

void		move_to(float position[3], float smooth);
void		turn_around(GtkBuilder *builder);
void		random_movement(GtkBuilder *builder);

#endif /* !GL_H_ */

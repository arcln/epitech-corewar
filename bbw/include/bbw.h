/*
** bbw.h for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 21 20:11:30 2017 Paul Laffitte
** Last update Sun Apr  2 22:23:11 2017 Paul Laffitte
*/

#ifndef BBW_H_
# define BBW_H_

# include <gtk/gtk.h>
# include <fmod.h>
# include "corewar.h"
# include "my.h"

# ifndef WIDTH
#  define WIDTH 1280
# endif /* !WIDTH */

# ifndef HEIGHT
#  define HEIGHT 720
# endif /* !HEIGHT */

# ifdef SYSCALL
#  undef SYSCALL
# endif /* !SYSCALL */

# define SYSCALL(x)	x

typedef struct {
  t_vector		songs;
  FMOD_SYSTEM		*system;
  FMOD_SOUND		*song;
  FMOD_DSP		*dsp;
  FMOD_CHANNELGROUP	*channel;
}			t_music;

extern t_corewar	*g_corewar;
extern t_music		*g_music;
extern t_list		*g_champions;
extern int		g_running;
extern pthread_t	g_vm_thread;

void			mat_model(int pos, float moy);
void			start_music();
float			get_spectrum();

GtkBuilder		*get_builder();

void			show_winner();

#endif /* !BBW_H_ */

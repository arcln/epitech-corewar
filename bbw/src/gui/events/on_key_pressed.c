/*
** on_key_pressed.c for g_corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/events/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 21 20:31:03 2017 Paul Laffitte
** Last update Sun Apr  2 01:53:16 2017 Arthur Chaloin
*/
#include <gtk/gtk.h>
#include "bbw.h"
#include "gl.h"

void	quit()
{
  pthread_cancel(g_vm_thread);
  if (g_corewar->cycle > 0)
    core_dump_memory(g_corewar);
  gtk_main_quit();
}

void	on_key_pressed(GtkWidget *widget, GdkEventKey *event)
{
  (void)widget;
  if (event->keyval == GDK_KEY_Escape)
    quit();
  if (event->keyval == GDK_KEY_Left)
    g_eye[0] += 7;
  if (event->keyval == GDK_KEY_Right)
    g_eye[0] -= 7;
  if (event->keyval == GDK_KEY_Up)
    g_eye[1] += 7;
  if (event->keyval == GDK_KEY_Down)
    g_eye[1] -= 7;
  if (event->keyval == GDK_KEY_Page_Up)
    g_eye[2] += 7;
  if (event->keyval == GDK_KEY_Page_Down)
    g_eye[2] -= 7;
}

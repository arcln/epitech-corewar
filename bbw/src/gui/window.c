/*
** window.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Mar 20 17:02:16 2017 Paul Laffitte
** Last update Sun Apr  2 21:57:42 2017 Paul Laffitte
*/
#include <gtk/gtk.h>
#include "gl.h"
#include "gui/events.h"
#include "gui/win_err.h"
#include "bbw.h"

static void	set_run()
{
  GtkBuilder	*builder;
  GtkWidget	*add_champ_btn;
  GtkWidget	*clear_btn;
  GtkWidget	*start_btn;

  if (g_running < 1)
    g_running = 1;
  else
    g_running = 0;
  builder = get_builder();
  add_champ_btn = GTK_WIDGET(gtk_builder_get_object(builder, "add_champ_btn"));
  clear_btn = GTK_WIDGET(gtk_builder_get_object(builder, "clear_btn"));
  start_btn = GTK_WIDGET(gtk_builder_get_object(builder, "start_btn"));
  gtk_widget_set_sensitive(add_champ_btn, FALSE);
  gtk_widget_set_sensitive(clear_btn, FALSE);
  gtk_widget_set_sensitive(start_btn, FALSE);
}

GtkBuilder		*get_builder()
{
  static GtkBuilder	*builder = NULL;
  GError		*err;

  if (!builder)
    {
      if (!(builder = gtk_builder_new()))
	return (NULL);
      err = NULL;
      gtk_builder_add_from_file(builder, "design/main_window.glade", &err);
      if (flush_err(&err) == 84)
	return (NULL);
    }
  return (builder);
}

void		windows_signal_connect(GtkBuilder *builder)
{
  GtkWidget	*window;
  GtkWidget	*chooser_win;
  GtkWidget	*chooser;

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  chooser_win = GTK_WIDGET(gtk_builder_get_object(builder, "chooser_win"));
  chooser = GTK_WIDGET(gtk_builder_get_object(builder, "chooser"));
  g_signal_connect(G_OBJECT(window), "key_press_event",
		   G_CALLBACK(on_key_pressed), NULL);
  g_signal_connect(G_OBJECT(chooser_win), "delete-event",
		   G_CALLBACK(gtk_widget_hide), NULL);
  g_signal_connect(G_OBJECT(chooser), "file-activated",
		   G_CALLBACK(add_champ), builder);
}

void		buttons_signal_connect(GtkBuilder *builder)
{
  GtkWidget	*add_champ_btn;
  GtkWidget	*clear_btn;
  GtkWidget	*start_btn;
  GtkWidget	*dump_btn;

  add_champ_btn = GTK_WIDGET(gtk_builder_get_object(builder, "add_champ_btn"));
  clear_btn = GTK_WIDGET(gtk_builder_get_object(builder, "clear_btn"));
  start_btn = GTK_WIDGET(gtk_builder_get_object(builder, "start_btn"));
  dump_btn = GTK_WIDGET(gtk_builder_get_object(builder, "dump_btn"));
  g_signal_connect(G_OBJECT(add_champ_btn), "button_press_event",
		   G_CALLBACK(choose_champ), builder);
  g_signal_connect(G_OBJECT(clear_btn), "button_press_event",
		   G_CALLBACK(clear_champ), NULL);
  g_signal_connect(G_OBJECT(start_btn), "button_press_event",
		   G_CALLBACK(set_run), NULL);
  g_signal_connect(G_OBJECT(dump_btn), "button_press_event",
		   G_CALLBACK(quit), NULL);
}

int		open_window()
{
  GtkWidget	*window;
  GtkWidget	*gl_area;
  GtkBuilder	*builder;

  g_corewar->winner = NULL;
  if ((builder = get_builder()) == NULL)
    return (84);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  gl_area = GTK_WIDGET(gtk_builder_get_object(builder, "gl_drawing_area"));
  windows_signal_connect(builder);
  buttons_signal_connect(builder);
  gtk_widget_set_events(GTK_WIDGET(gl_area),
			GDK_EXPOSURE_MASK | GDK_BUTTON_PRESS_MASK);
  g_signal_connect(gl_area, "realize", G_CALLBACK(init_gl), NULL);
  g_signal_connect(gl_area, "render", G_CALLBACK(render_gl), builder);
  gtk_window_set_title(GTK_WINDOW(window), "Bad Boys du Corewar");
  gtk_widget_show(window);
  gtk_main();
  return (0);
}

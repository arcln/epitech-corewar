/*
** winner.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Apr  2 22:22:46 2017 Paul Laffitte
** Last update Sun Apr  2 22:23:54 2017 Paul Laffitte
*/

#include <gtk/gtk.h>
#include "bbw.h"

void		show_winner()
{
  GtkBuilder	*builder;
  GtkWidget	*winner_win;
  GtkWidget     *winner_name;
  GtkWidget     *winner_comment;
  char		*name;
  char		*comment;

  builder = get_builder();
  winner_win = GTK_WIDGET(gtk_builder_get_object(builder, "winner_win"));
  winner_name = GTK_WIDGET(gtk_builder_get_object(builder, "winner_name"));
  winner_comment = GTK_WIDGET(gtk_builder_get_object(builder,
						     "winner_comment"));
  name = my_str_concat("Name: ", g_corewar->winner->header.name);
  comment = my_str_concat("Comment: ", g_corewar->winner->header.comment);
  gtk_label_set_text(GTK_LABEL(winner_name), name);
  gtk_label_set_text(GTK_LABEL(winner_comment), comment);
  gtk_widget_show(winner_win);
  g_signal_connect(G_OBJECT(winner_win),
		   "delete-event", G_CALLBACK(gtk_widget_hide), NULL);
  g_corewar->winner = NULL;
}

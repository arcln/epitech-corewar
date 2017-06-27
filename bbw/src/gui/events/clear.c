/*
** clear.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/events/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Mar 31 18:50:52 2017 Paul Laffitte
** Last update Sun Apr  2 01:32:40 2017 Arthur Chaloin
*/

#include "bbw.h"

void	clear_champ()
{
  GtkBuilder	*builder;
  GtkWidget	*champ_lab;
  GtkWidget	*add_champ_btn;

  builder = get_builder();
  while (g_champions)
    list_pop(&g_champions);
  add_champ_btn = GTK_WIDGET(gtk_builder_get_object(builder,
						    "add_champ_btn"));
  gtk_widget_set_sensitive(add_champ_btn, TRUE);
  champ_lab = GTK_WIDGET(gtk_builder_get_object(builder, "champ_lab"));
  gtk_label_set_text(GTK_LABEL(champ_lab), "");
}

/*
** choose_champ.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Mar 30 16:32:00 2017 Paul Laffitte
** Last update Sun Apr  2 01:32:30 2017 Arthur Chaloin
*/
#include <string.h>
#include <stdlib.h>
#include "bbw.h"

static char	*get_champ_name(char *filename)
{
  int		i;
  int		start;
  char		*name;

  start = 0;
  i = 0;
  while (filename[i])
    {
      if (filename[i] == '/')
	start = i + 1;
      i++;
    }
  if (!(name = my_strdup(filename + start)))
    return (NULL);
  if (name[strlen(name) - 1] == 's')
    {
      name[i - start - 2] = '\n';
      name[i - start - 1] = '\0';
    }
  else
    {
      name[i - start - 4] = '\n';
      name[i - start - 3] = '\0';
    }
  return (name);
}

static int	champ_len()
{
  t_list	*iterator;
  char		*name;
  int		len;

  len = 0;
  iterator = g_champions;
  while (iterator)
    {
      if (!(name = get_champ_name(iterator->element)))
	return (-1);
      len += my_strlen(name);
      iterator = iterator->next;
    }
  return (len);
}

static char	*get_new_content(char *filename)
{
  char		*new_content;
  char		*name;
  int		len;
  t_list	*iterator;

  list_push(&g_champions, filename);
  if ((len = champ_len()) < 0)
    return (NULL);
  if (!(new_content = malloc(sizeof(char) * len)))
    return (NULL);
  new_content[0] = '\0';
  iterator = g_champions;
  while (iterator)
    {
      if (!(name = get_champ_name(iterator->element)))
	return (NULL);
      my_strcat(new_content, name);
      iterator = iterator->next;
    }
  new_content[len] = '\0';
  return (new_content);
}

void		add_champ(GtkWidget *widget)
{
  GtkBuilder	*builder;
  GtkWidget	*champ_lab;
  GtkWidget	*add_champ_btn;
  char		*filename;

  builder = get_builder();
  gtk_widget_hide(gtk_widget_get_parent(gtk_widget_get_parent(widget)));
  filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget));
  champ_lab = GTK_WIDGET(gtk_builder_get_object(builder, "champ_lab"));
  gtk_label_set_text(GTK_LABEL(champ_lab), get_new_content(filename));
  if (list_len(&g_champions) == 4)
    {
      add_champ_btn = GTK_WIDGET(gtk_builder_get_object(builder,
							"add_champ_btn"));
      gtk_widget_set_sensitive(add_champ_btn, FALSE);
    }
}

void		choose_champ(GtkWidget *button, GdkEvent *event,
			     GtkBuilder *builder)
{
  GtkWidget	*chooser_win;
  GtkWidget	*chooser;

  (void)button;
  (void)event;
  chooser_win = GTK_WIDGET(gtk_builder_get_object(builder, "chooser_win"));
  chooser = GTK_WIDGET(gtk_builder_get_object(builder, "chooser"));
  gtk_widget_show(chooser_win);
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser),
				      "../champions");
}

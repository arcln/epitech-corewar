/*
** events.h for coerwar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/include/gui/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 21 20:33:25 2017 Paul Laffitte
** Last update Fri Mar 31 19:12:00 2017 Paul Laffitte
*/

#ifndef EVENTS_H_
# define EVENTS_H_

void	on_key_pressed(GtkWidget *widget, GdkEventKey *event);

void	add_champ(GtkWidget *widget);
void	choose_champ(GtkWidget *button, GdkEvent *event, GtkBuilder *builder);

void	clear_champ();

void	quit();

#endif /* !EVENTS_H_ */

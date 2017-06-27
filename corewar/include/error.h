/*
** error.h for corewar in /home/arthur/B2/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Chaloin
** Login   <arthur@epitech.net>
**
** Started on  Tue Feb 28 10:58:59 2017 Arthur Chaloin
** Last update Thu Mar  2 14:32:41 2017 Arthur Chaloin
*/

#ifndef ERROR_H_
# define ERROR_H_

# define INVALID_ARG_ERR	"Arguments are invalid.\n"

int	display_help();
void	throw_error(char *err) __attribute__((noreturn));

#endif /* !ERROR_H_ */

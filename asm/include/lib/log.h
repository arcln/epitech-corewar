/*
** syntax.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Mar 24 17:09:22 2017 Thomas ARBONA
** Last update Fri Mar 31 12:30:54 2017 Thomas ARBONA
*/
#ifndef LOG_H_
# define LOG_H_

# include "lib/io.h"

# define SERR_EMPTY_FILE	"file is empty"
# define SERR_MISSING_NAME	"missing .name"
# define SERR_NAME_TOOLONG	"the program name is too long"
# define SERR_MISSING_COMMENT	"missing .comment"
# define SERR_COMMENT_TOOLONG	"the comment is too long"
# define SERR_BAD_TOKEN		"bad token"
# define SERR_UNKNOWN_OP	"unknown operator ‘\e[1m%s\e[21m’"
# define SERR_MISSING_PARAMS	"missing parameter for ‘\e[1m%s\e[21m’"
# define SERR_UNEXP_PARAMS	"unexpected parameter ‘\e[1m%s\e[21m’"
# define SERR_INVALID_PARAMS	"invalid parameter type"
# define SERR_BAD_DIRARG	"missing value after direct character"
# define SERR_UNDEF_LABEL	"undefined label ‘\e[1m%s\e[21m’"
# define SERR_ALDEF_LABEL	"label ‘\e[1m%s\e[21m’ is already defined"
# define SERR_INV_REG		"invalid register number ‘\e[1m%s\e[21m’"

int	log_syntaxwarning(t_io *io, char *error, int mode);
int	log_syntaxerror(t_io *io, char *error, int mode);
int	log_builderror(t_io *io);

#endif /* !LOG_H_ */

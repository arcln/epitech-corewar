/*
** force.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 15:14:52 2017 Thomas ARBONA
** Last update Tue Mar 28 19:11:54 2017 Thomas ARBONA
*/
#ifndef ENDIAN_FORCE_H_
# define ENDIAN_FORCE_H_

# include <stdint.h>

typedef union	u_revi16 {
  int16_t	i;
  char		c[2];
}		t_revi16;

typedef union	u_revi32 {
  int32_t	i;
  char		c[4];
}		t_revi32;

#endif /* !ENDIAN_FORCE_H_ */

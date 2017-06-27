/*
** endian.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 27 14:40:04 2017 Thomas ARBONA
** Last update Tue Mar 28 19:12:12 2017 Thomas ARBONA
*/
#ifndef ENDIAN_H_
# define ENDIAN_H_

# include <stdint.h>

int	endian_isbig();

int16_t	endian_fbigi16(int16_t);
int32_t	endian_fbigi32(int32_t);

#endif /* !ENDIAN_H_ */

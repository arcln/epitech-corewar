/*
** asm.h for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 14:27:48 2017 Thomas ARBONA
** Last update Tue Mar 28 15:48:33 2017 Thomas ARBONA
*/
#ifndef ASM_H_
# define ASM_H_

# define NORMAL		0
# define VERBOSE	1

int	asm_compile(char *in_path, char *out_path, const int mode);

#endif /* !ASM_H_ */

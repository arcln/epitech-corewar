/*
** asm.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 14:24:42 2017 Thomas ARBONA
** Last update Tue Mar 28 14:11:44 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib/header.h"
#include "lib/body.h"
#include "lib/io.h"
#include "lib/log.h"

int		asm_compile(char *in_path, char *out_path, const int mode)
{
  t_io		io;
  t_header	header;

  if (io_init(&io, in_path, out_path, mode) == -1)
    return (log_builderror(&io));
  if (header_compile(&io, &header) == -1)
    return (log_builderror(&io));
  if (body_compile(&io) == -1)
    return (log_builderror(&io));
  if (io_outwrite(&io) == -1)
    return (log_builderror(&io));
  return (0);
}

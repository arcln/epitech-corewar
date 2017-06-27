/*
** precompile.c for asm in /home/arbona/tek1/CPE/CPE_2016_corewar/asm/src/lib
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 28 21:48:34 2017 Thomas ARBONA
** Last update Sun Apr  2 23:20:04 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "lib/body/precompile.h"
#include "lib/body.h"
#include "lib/io.h"
#include "lib/op.h"
#include "lib/log.h"
#include "lib/helper.h"
#include "my.h"

int		body_precompile(t_io *io)
{
  t_vector	labels;

  vector_init(&labels);
  if (precompile_1(io, &labels) == -1 ||
      precompile_2(io, &labels) == -1 ||
      precompile_3(io, &labels) == -1)
    return (-1);
  vector_free(&labels);
  return (0);
}

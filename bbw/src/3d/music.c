/*
** g_music.c for tetris in /home/arthur/B2/PSU/PSU_2016_tetris/src/g_music/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Mar 20 15:44:34 2017 Arthur Chaloin
** Last update Sun Apr  2 01:44:31 2017 Arthur Chaloin
*/
#include <dirent.h>
#include <stdlib.h>
#include <fmod.h>
#include <time.h>
#include <math.h>
#include "bbw.h"
#include "my.h"
#include "vector.h"

static char	*get_music()
{
  DIR		*dir;
  struct dirent	*file;
  t_vector	files;
  char		*choice;

  vector_init(&files);
  dir = opendir("../music/");
  while ((file = readdir(dir)))
    vector_push(&files, (void *)file);
  while ((choice = my_str_concat("../music/",
			(vector_get(&files, rand() % vector_getsize(&files),
			struct dirent))->d_name)) && choice[9] == '.');
  return (choice);
}

void	start_music()
{
  srand(time(NULL));
  FMOD_System_Create(&(g_music->system));
  FMOD_System_Init(g_music->system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(g_music->system, get_music(),
	FMOD_2D | FMOD_CREATESTREAM, 0, &(g_music->song));
  FMOD_System_PlaySound(g_music->system, g_music->song, 0, 0, NULL);
  FMOD_System_GetMasterChannelGroup(g_music->system, &(g_music->channel));
  FMOD_System_CreateDSPByType(g_music->system,
			      FMOD_DSP_TYPE_FFT, &(g_music->dsp));
}

float				get_spectrum(int index)
{
  FMOD_DSP_PARAMETER_FFT	*fft;

  FMOD_ChannelGroup_AddDSP(g_music->channel, 0, g_music->dsp);
  FMOD_DSP_GetParameterData(g_music->dsp, FMOD_DSP_FFT_SPECTRUMDATA,
			    (void *)&fft, 0, 0, 0);
  return ((fft->length > sqrt(MEM_SIZE)) ?
	  fft->spectrum[0][index % (int)sqrt(MEM_SIZE)] * 10 : 0);
}

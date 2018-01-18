#ifndef SDL_STUFF_INCLUDED
#define SDL_STUFF_INCLUDED


#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL/SDL.h>
#endif

typedef struct configuration_decl
{

  int size_x;
  int size_y;

}config;

sdlPlay(config * cfg);

sdlSettings(config * cfg);

#endif

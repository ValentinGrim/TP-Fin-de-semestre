#include "sdl_win.h"
#include <unistd.h>


sdlPlay(config * cfg)
{

  SDL_Surface * window = NULL;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

}

sdlSettings(config * cfg)
{

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

  window = SDL_SetVideoMode(256, 512, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  if (window == NULL)
  {

      printf("Unable to open settings : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);

  }

  SDL_WM_SetCaption("Settings", NULL);
  SDL_FillRect(window, NULL, SDL_MapRGB(window->format,245,80,0));

}

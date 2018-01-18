#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include"sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"
#include <stdio.h>
#include <SDL/SDL.h>

int main()
{

  SDL_Surface *window = NULL;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  window = SDL_SetVideoMode(256, 512, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  if (window == NULL) // Si l'ouverture a échoué, on le note et on arrête
  {

      printf("Impossible d'ouvrir la fenêtre : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);

  }

  SDL_WM_SetCaption("Menu Bonus", NULL);
  SDL_Surface *icon = NULL;
  icon = SDL_LoadBMP("icon.bmp");
  SDL_WN_SetIcon(icon, NULL);
  SDL_MapRGB(window->format,245,80,0);
  
  while(1);

  if(!sdl_startup())
      return -1;

  fpsInit();

  // program main loop
  do
  {

      fpsStep();

  }
  while(sdl_loop());
  // end main loop

  sdl_clean();
  return 0;
}

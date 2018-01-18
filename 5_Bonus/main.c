#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include"sdl_stuff.h"

#include "fpstimer.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include "main.h"

int main()
{
  SDL_Rect position;
  
  SDL_Surface * bPlayImg;
  SDL_Surface * bSetImg;
  SDL_Surface * bExitImg;

  SDL_Surface *window = NULL;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  window = SDL_SetVideoMode(256, 512, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  if (window == NULL) // Si l'ouverture a échoué, on le note et on arrête
  {

      printf("Impossible d'ouvrir la fenêtre : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);

  }

  SDL_WM_SetCaption("Menu Bonus", NULL);
  SDL_FillRect(window, NULL, SDL_MapRGB(window->format,245,80,0));

  bPlayImg = SDL_LoadBMP("Button_Play.bmp");
  bSetImg = SDL_LoadBMP("Button_Settings.bmp");
  bExitImg = SDL_LoadBMP("Button_Exit.bmp");

  int continuer = 1;
  while(continuer == 1)
  {

    SDL_WaitEvent(&event);
    switch(event.type)
    {

      case SDL_QUIT:
        continuer = 0;
        break;

      case SDL_MOUSEBUTTONUP:
        if(event.button.y > 38 && event.button.y < 90 && event.button.x > 27 && event.button.x < 229)
        
        if(event.button.y > 166 && event.button.y < 218 && event.button.x > 27 && event.button.x < 229)
        
        if(event.button.y > 422 && event.button.y < 474 && event.button.x > 27 && event.button.x < 229)
          {

              continuer = 0;
              
          }
        break;

    }

    SDL_Flip(window);
	
    position.x = 28;
    position.y = 39;
    SDL_BlitSurface(bPlayImg, NULL, window, &position);
    
    position.x = 28;
    position.y = 167;
    SDL_BlitSurface(bSetImg, NULL, window, &position);
    
    position.x = 28;
    position.y = 423;
    SDL_BlitSurface(bExitImg, NULL, window, &position);

  }

  sdl_clean();

  return 0;

}

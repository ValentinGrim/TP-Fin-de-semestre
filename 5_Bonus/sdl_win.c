#include "sdl_win.h"
#include <unistd.h>

sdlSettings(config * cfg)
{

  SDL_Rect position;

  SDL_Surface * b431Img, * b432Img, * b1691Img, * b1692Img;
  SDL_Surface * window = NULL;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

  window = SDL_SetVideoMode(925, 512, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  if (window == NULL)
  {

      printf("Unable to open settings : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);

  }

  SDL_WM_SetCaption("Settings", NULL);
  SDL_FillRect(window, NULL, SDL_MapRGB(window->format,245,80,0));

  b431Img = SDL_LoadBMP("4tiers1.bmp");
  b432Img = SDL_LoadBMP("4tiers2.bmp");
  b1691Img = SDL_LoadBMP("16neuvieme1.bmp");
  b1692Img = SDL_LoadBMP("16neuvieme2.bmp");

  int continuer = 1

  while(continuer == 1)
  {

    SDL_WaitEvent(&event);

    switch(event.type)
    {

      case SDL_QUIT:
          continuer = 0;
          break;

      case SDL_MOUSEBUTTONUP:
          if(event.button.y > 38 && event.button.y < 89 && event.button.x > 24 && event.button.x < 226 &SDL_BUTTON_LEFT)
          {

            cfg->size_x = 512;
            cfg->size_y = 512;

          }

          if(event.button.y > 38 && event.button.y < 89 && event.button.x > 249 && event.button.x < 451 &SDL_BUTTON_LEFT)
          {

            cfg->size_x = 1024;
            cfg->size_y = 1024;

          }

          if(event.button.y > 38 && event.button.y < 89 && event.button.x > 474 && event.button.x < 676 &SDL_BUTTON_LEFT)
          {

            cfg->size_x = 1366;
            cfg->size_y = 768;

          }

          if(event.button.y > 38 && event.button.y < 89 && event.button.x > 699 && event.button.x < 901 &SDL_BUTTON_LEFT)
          {

            cfg->size_x = 1920;
            cfg->size_y = 1080;

          }
      break;

    }

    SDL_Flip(window);

    position.x = 25;
    position.y = 39;
    SDL_BlitSurface(b431Img, NULL, window, &position);

    position.x = 250;
    position.y = 39;
    SDL_BlitSurface(b432Img, NULL, window, &position);

    position.x = 475;
    position.y = 39;
    SDL_BlitSurface(b1691Img, NULL, window, &position);

    position.x = 700;
    position.y = 39;
    SDL_BlitSurface(b1692Img, NULL, window, &position);

  }

    sdl_clean();

    return 0;

}

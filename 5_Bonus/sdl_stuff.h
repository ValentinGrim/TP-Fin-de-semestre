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


#define WINDOW_SIZE 512
// le bitmap fait 32x32 pixel, la fenettre 512x512
#define BALL_RADIUS (16.0f/(float)WINDOW_SIZE)

int sdl_loop();
int sdl_startup();
void sdl_clean();

// la fenettre s'etend de [0,0] � [+1,+1]
void sdl_setBallPosition(float x,float y);


#endif

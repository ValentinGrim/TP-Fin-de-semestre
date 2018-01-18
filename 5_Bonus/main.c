#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "sdl_stuff.h"
#include "sdl_win.h"
#include "fpstimer.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include "main.h"

int main()
{

  config cfg;

  cfg.size_x = 512;
  cfg.size_y = 512;
  cfg.music_state = 1;

  int continuer = 1;

  while(continuer == 1)
  {

    if(continuer == 1)
    {

      continuer = sdlMenu(cfg);

    }

    if(continuer == 2)
    {

      float dt;   // Déclaration de la variable delta
      Balle Balle_v = chargerBalle("balle.txt"); // Déclaration de la balle et chargement des paramètres du fichier texte.

      if(!sdl_startup(cfg))
          return -1;

      fpsInit();
      // boucle pour mettre a jour en continue la simulation
      do
      {
          fpsStep();


          dt=fpsGetDeltaTime(); // Assigne le temps entre deux frames à la variable dt
          majPosition(&Balle_v, dt); // Met à jour la position de la balle en fonction de dt

          if(Balle_v.position.x < BALL_RADIUS) // Condition si balle touche le bord gauche
          {

              Balle_v.vitesse.x = (-Balle_v.vitesse.x); // Inversement de la vitesse pour faire partir la balle dans l'autre sens et reduction de la vitesse (perte d'energie)
              Balle_v.position.x = BALL_RADIUS;               // Mise à jour de la position de la balle pour qu'elle ne sorte pas de l'écran

          }

          if(Balle_v.position.x > 1 - BALL_RADIUS) //Condition si balle touche le bord droit
          {

              Balle_v.vitesse.x = (-Balle_v.vitesse.x); // Inversement de la vitesse pour faire partir la balle dans l'autre sens et reduction de la vitesse (perte d'energie)
              Balle_v.position.x = 1 - BALL_RADIUS;           // Mise à jour de la position de la balle pour qu'elle ne sorte pas de l'écran

          }

          if(Balle_v.position.y < BALL_RADIUS) //Condition si balle touche le bord haut
          {

              Balle_v.vitesse.y = (-Balle_v.vitesse.y); // Inversement de la vitesse pour faire partir la balle dans l'autre sens et reduction de la vitesse (perte d'energie)
              Balle_v.position.y = BALL_RADIUS;               // Mise à jour de la position de la balle pour qu'elle ne sorte pas de l'écran
          }

          if(Balle_v.position.y > 1 - BALL_RADIUS)	// Condition si balle touche le bord bas
          {

              Balle_v.vitesse.y = (-Balle_v.vitesse.y); // Inversement de la vitesse pour faire partir la balle dans l'autre sens et reduction de la vitesse (perte d'energie)
              Balle_v.position.y = 1 - BALL_RADIUS;           // Mise à jour de la position de la balle pour qu'elle ne sorte pas de l'écran

          }

          sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y); // Permet d'afficher la balle avec sa nouvelle position.

      }
      while(sdl_loop(cfg));

      sdl_clean();

    }

    if(continuer == 3)
    {

       continuer = sdlSettings(&cfg);

    }

  }

  return 0;

}

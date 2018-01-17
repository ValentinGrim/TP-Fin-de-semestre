#include <stdlib.h>
#include <stdio.h>
#include "vecteur.h"
#include "balle.h"
#include "sdl_stuff.h"
#include "fpstimer.h"
#include <math.h>



int main ( int argc, char** argv )
{

    if (agrc < 3) //test des arguments entrée de le min quitter s'il n'y en a pas assez.
    {

      printf("Il manque un ou plusieurs arguments.");
      return EXIT_FAILURE; // On quitte le programme

    }
    
    float dt; // Variable delta donner le temps entre deux frame
    Balle Balle_v = chargerBalle(argv[1]); //Déclaration de la balle et chargment des parametre du fichier texte.

    if(!sdl_startup())
        return -1;

    fpsInit();
    // boucle pour mettre a jour en continue la simulation
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
       	dt=fpsGetDeltaTime(); // Assigner le temsp entre deux frames a la variable dt
        majPosition(&Balle_v, dt); //Met a jours la position de la balle

        if(Balle_v.position.x < BALL_RADIUS) //Condition si balle touche le bord gauche
        {

            Balle_v.vitesse.x = (-Balle_v.vitesse.x) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            Balle_v.position.x = BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(Balle_v.position.x > 1 - BALL_RADIUS) //Condition si balle touche le bord droit
        {

            Balle_v.vitesse.x = (-Balle_v.vitesse.x) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            Balle_v.position.x = 1 - BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(Balle_v.position.y < BALL_RADIUS) //Condition si balle touche le bord bas
        {

            Balle_v.vitesse.y = (-Balle_v.vitesse.y) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            Balle_v.position.y = BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(Balle_v.position.y > 1 - BALL_RADIUS) //Condition si balle touche le bord haut

            Balle_v.vitesse.y = (-Balle_v.vitesse.y) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            Balle_v.position.y = 1 - BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y); //Permet d'afficher la balle avec sa nouvelle position.

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}

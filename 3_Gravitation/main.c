#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "vecteur.h"
#include "sdl_stuff.h"
#include "balle.h"
#include "decl.h"
#include "fpstimer.h"

AttracteurList gAttractList; //Variable générale du nombre et de la position des attracteurs

    // fonction appell�e lorsque l'on appuie avec le bouton gauche de la souris
void clicSouris(float x, float y)
{
    // NB : une variable locale declaree static ne perd pas sa valeur entre deux appels a 	la fonction
    // son initialisation est effectu� au tout premier appel de la fonction
    // on s'en sert ici pour savoir quel attracteur on est en train de positioner
    static int attracteurCurrent = 0 ;

    // TODO gerer les position de la liste des attracteurs ici
    gAttractList.utiliseMoi[attracteurCurrent] = 1; // Mettre la variable utiliseMoi a 1 si un attracteur a été posé (initialement a 0)
    gAttractList.positionAttracteur[attracteurCurrent] = creerVect(x,y); //Créé le vecteur positionAttracteuravec les valeurs x et y du clic souris

    sdl_setAttracteurPosition(attracteurCurrent,x,y);
    attracteurCurrent ++;
    attracteurCurrent %=NB_ATTRACTEURS;

}

int main ( int argc, char** argv )
{

    if (agrc < 3) //test des arguments entrée de le main quitter s'il n'y en a pas assez.
    {

      printf("Il manque un ou plusieurs arguments.");
      return EXIT_FAILURE; // On quitte le programme

    }
    float dt; // Variable delta donner le temps entre deux frame
    Balle Balle_v = chargerBalle(argv[1]); //Déclaration de la balle et chargment des parametre du fichier texte.

    if(!sdl_startup())
        return -1;

    fpsInit();
    // program main loop
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
        dt=fpsGetDeltaTime(); // Assigner le temsp entre deux frames a la variable dt
        majPosition(&Balle_v, &gAttractList, dt); //Met a jours la position de la balle en fonction de dt et de la liste des attracteurs

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

    } while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}

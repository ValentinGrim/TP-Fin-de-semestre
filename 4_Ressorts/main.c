#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include"sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"


Balle gBalleTab[NB_BALLES]; //Création du table de balles

void dragSouris(float x, float y)
{
    gBalleTab[0].position.x=x; //Récuperer la position x de la souris pour la position de la première balle
    gBalleTab[0].position.y=y; //Récuperer la position y de la souris pour la position de la première balle
}



int main ( int argc, char** argv )
{

    if (agrc < 2) //test des arguments entrée de le main quitter s'il n'y en a pas assez.
    {

      printf("Il manque un ou plusieurs arguments.");
      return EXIT_FAILURE; // On quitte le programme

    }

    if(!sdl_startup())
        return -1;

    fpsInit();

    float dt; // Variable delta donner le temps entre deux frames
    int i;
    for(i=0;i<NB_BALLES;i++) //Boucles principale pour calcule de la poistion de toute les balles.
    {
        gBalleTab[i] = chargerBalle(argv[1]); //Initiliser la struture balle avec les valeurs du fichier de configuration texte

    // relier les balles entre elles
    // ....
	gBalleTab[0].ballePrecedente = NULL; // La premiere balle n'a pas deballe avant elle donc init a NULL
	gBalleTab[0].balleSuivante = &gBalleTab[1]; // Relier a la balle suivante

	//gBalleTab[i-1].ballePrecedente = &gBalleTab[i-2];
	//gBalleTab[i-1].balleSuivante = &gBalleTab[i];

	gBalleTab[i].ballePrecedente = &gBalleTab[i-1]; //relie tout les autres valle entre elle
	gBalleTab[i].balleSuivante = &gBalleTab[i+1]; // meme fonction

	//gBalleTab[i+1].ballePrecedente = &gBalleTab[i];
	//gBalleTab[i+1].balleSuivante = &gBalleTab[i+2];

	gBalleTab[NB_BALLES-1].ballePrecedente = &gBalleTab[NB_BALLES-2]; //relie la derniere balle a l'avant derniere
	gBalleTab[NB_BALLES-1].balleSuivante = NULL; // la derniere balle n'a pas de balle suivante donc init a NULL

    }
    // program main loop
    do
    {

        fpsStep();

        // TODO : mettre a jour les balles
        dt=fpsGetDeltaTime();  // Assigner le temsp entre deux frames a la variable dt
    for(i=0; i<NB_BALLES; i++) // Boucle prinipale pour calcule sur toute les balles
    {

        majPosition(&gBalleTab[i], dt); //Mise a jours de la position de chaque balle une par une en fonction de dt

        if(gBalleTab[i].position.x < BALL_RADIUS) //Condition si balle touche le bord gauche
        {

            gBalleTab[i].vitesse.x = (-gBalleTab[i].vitesse.x) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            gBalleTab[i].position.x = BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(gBalleTab[i].position.x > 1 - BALL_RADIUS) //Condition si balle touche le bord droit
        {

            gBalleTab[i].vitesse.x = (-gBalleTab[i].vitesse.x) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            gBalleTab[i].position.x = 1 - BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(gBalleTab[i].position.y < BALL_RADIUS) //Condition si balle touche le bord haut
        {

           gBalleTab[i].vitesse.y = (-gBalleTab[i].vitesse.y) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
           gBalleTab[i].position.y = BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }

        if(gBalleTab[i].position.y > 1 - BALL_RADIUS) //Condition si balle touche le bord bas
        {

            gBalleTab[i].vitesse.y = (-gBalleTab[i].vitesse.y) * 0.9; //inversement de la vitesse pour faire partir la balle dans l'autre sens plus reduction de la vitesse (perte d'energie)
            gBalleTab[i].position.y = 1 - BALL_RADIUS; //Mise a jours de la position de la balle pour ne pas qu'elle sorte de l'écran

        }


        sdl_setBallPosition(i,gBalleTab[i].position.x,gBalleTab[i].position.y); //Affichage de chaqeu balle une par une

    }

    }
    while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}

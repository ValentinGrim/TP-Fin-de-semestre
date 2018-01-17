#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "vecteur.h"
#include "sdl_stuff.h"
#include "balle.h"
#include "decl.h"
#include "fpstimer.h"

AttracteurList gAttractList;

    // fonction appell�e lorsque l'on appuie avec le bouton gauche de la souris
void clicSouris(float x, float y)
{
    // NB : une variable locale declaree static ne perd pas sa valeur entre deux appels a 	la fonction
    // son initialisation est effectu� au tout premier appel de la fonction
    // on s'en sert ici pour savoir quel attracteur on est en train de positioner
    static int attracteurCurrent = 0 ;

    // TODO gerer les position de la liste des attracteurs ici
    gAttractList.utiliseMoi[attracteurCurrent] = 1;
    gAttractList.positionAttracteur[attracteurCurrent] = creerVect(x,y);

    sdl_setAttracteurPosition(attracteurCurrent,x,y);
    attracteurCurrent ++;
    attracteurCurrent %=NB_ATTRACTEURS;
    

}



int main ( int argc, char** argv )
{
	
    float dt;
    Balle Balle_v;
    Balle_v = chargerBalle(argv[1]);

    if(!sdl_startup())
        return -1;

    fpsInit();
    // program main loop
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
        dt=fpsGetDeltaTime();
        majPosition(&Balle_v, &gAttractList, dt);
	
        if(Balle_v.position.x < BALL_RADIUS)
        {

            Balle_v.vitesse.x = (-Balle_v.vitesse.x) * 0.9;
            Balle_v.position.x = BALL_RADIUS;

        }

        if(Balle_v.position.x > 1 - BALL_RADIUS)
        {

            Balle_v.vitesse.x = (-Balle_v.vitesse.x) * 0.9;
            Balle_v.position.x = 1 - BALL_RADIUS;

        }

        if(Balle_v.position.y < BALL_RADIUS)
        {

            Balle_v.vitesse.y = (-Balle_v.vitesse.y) * 0.9;
            Balle_v.position.y = BALL_RADIUS;

        }

        if(Balle_v.position.y > 1 - BALL_RADIUS)
        {

            Balle_v.vitesse.y = (-Balle_v.vitesse.y) * 0.9;
            Balle_v.position.y = 1 - BALL_RADIUS;

        }

        printf("x est %f et y est %f et le temps est %f \n",Balle_v.position.x,Balle_v.position.y,dt);
        sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y);
        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calcul�e pour la balle
        sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y);

    } while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}

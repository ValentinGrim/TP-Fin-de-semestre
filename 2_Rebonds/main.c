#include <stdlib.h>
#include <stdio.h>
#include "vecteur.h"
#include "balle.h"
#include "sdl_stuff.h"
#include "fpstimer.h"
#include <math.h>



int main ( int argc, char** argv )
{

    float dt;
    Balle Balle_v;
    Balle_v = chargerBalle(argv[1]);

    if(!sdl_startup())
        return -1;

    fpsInit();
    // boucle pour mettre a jour en continue la simulation
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
       	dt=fpsGetDeltaTime();
        majPosition(&Balle_v, dt);
        
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

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}

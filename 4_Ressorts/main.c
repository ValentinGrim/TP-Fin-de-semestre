#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include"sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"



// juste pour le basecode, a remplacer par le tableau de balles
Balle gBalleTab[NB_BALLES];



// fonction appellée lorsque le bouton de la souris est maintenu
void dragSouris(float x, float y)
{
    gBalleTab[0].position.x=x;
    gBalleTab[0].position.y=y;
}



int main ( int argc, char** argv )
{
    

    if(!sdl_startup())
        return -1;

    fpsInit();
	
    
    // TODO :
    // creer les balles
    // ....     
    float dt;
    int i;
    for(i=0;i<NB_BALLES;i++) 
    {
        gBalleTab[i] = chargerBalle(argv[1]);
    
    // relier les balles entre elles
    // ....
	gBalleTab[0].ballePrecedente = NULL; 
	gBalleTab[0].balleSuivante = &gBalleTab[1];
	
	//gBalleTab[i-1].ballePrecedente = &gBalleTab[i-2];
	//gBalleTab[i-1].balleSuivante = &gBalleTab[i];
	
	gBalleTab[i].ballePrecedente = &gBalleTab[i-1];
	gBalleTab[i].balleSuivante = &gBalleTab[i+1];
	
	//gBalleTab[i+1].ballePrecedente = &gBalleTab[i];
	//gBalleTab[i+1].balleSuivante = &gBalleTab[i+2];
	
	gBalleTab[NB_BALLES-1].ballePrecedente = &gBalleTab[NB_BALLES-2];
	gBalleTab[NB_BALLES-1].balleSuivante = NULL;
	
    }	
    // program main loop
    do
    {
      
        fpsStep();

        // TODO : mettre a jour les balles
        dt=fpsGetDeltaTime();
    for(i=0; i<NB_BALLES; i++)
    {
       	
        majPosition(&gBalleTab[i], dt);
        
        if(gBalleTab[i].position.x < BALL_RADIUS)
        {
            
            gBalleTab[i].vitesse.x = (-gBalleTab[i].vitesse.x) * 0.9;
            gBalleTab[i].position.x = BALL_RADIUS;
            
        }
        
        if(gBalleTab[i].position.x > 1 - BALL_RADIUS)
        {
            
            gBalleTab[i].vitesse.x = (-gBalleTab[i].vitesse.x) * 0.9;
            gBalleTab[i].position.x = 1 - BALL_RADIUS;
            
        }
        
        if(gBalleTab[i].position.y < BALL_RADIUS)
        {
            
           gBalleTab[i].vitesse.y = (-gBalleTab[i].vitesse.y) * 0.9;
           gBalleTab[i].position.y = BALL_RADIUS;
            
        }
        
        if(gBalleTab[i].position.y > 1 - BALL_RADIUS)
        {
            
            gBalleTab[i].vitesse.y = (-gBalleTab[i].vitesse.y) * 0.9;
            gBalleTab[i].position.y = 1 - BALL_RADIUS;
            
        }
        
       
        sdl_setBallPosition(i,gBalleTab[i].position.x,gBalleTab[i].position.y);

    }
        // la balle nb 0 est manipulée a la souris a titre d'exemple
	//sdl_setBallPosition(0,gBalleTab[0].position.x,gBalleTab[0].position.y);

        // les autres sont mises a jour differement  
        
 	
      /*  for(i=0; i<NB_BALLES; i++)
        {
            //TODO : maj de la balle
 
             sdl_setBallPosition(i,gBalleTab[i].position.x,gBalleTab[i].position.y);
        }*/
       
    }
    while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}


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
       	float a=1,b=1, dt=fpsGetDeltaTime();
       	majPosition(&Balle_v, dt);
       	Balle_v.position.x=Balle_v.position.x*a;
       	Balle_v.position.y=Balle_v.position.y*b;
       	while((Balle_v.position.x<0 || Balle_v.position.x>1)||(Balle_v.position.y<0 || Balle_v.position.y>1))
       	if(Balle_v.position.x<0)
        {
       	a=-0.8;
       				if(Balle_v.position.y<0)
       				b=-0.8;
       				else if(Balle_v.position.y>1)
       				b=-0.8;
       	}
       	else if(Balle_v.position.x>1)
       	{
       	a=0.8;
       				if(Balle_v.position.y<0)
       				b=-0.8;
       				else if(Balle_v.position.y>1)
       				b=-0.8;
        }
        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calcul�e pour la balle
        printf("x est %f et y est %f et le temps est %f \n",Balle_v.position.x,Balle_v.position.y,dt);
        sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y);

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}

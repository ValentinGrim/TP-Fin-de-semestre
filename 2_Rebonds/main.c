
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
        int secu;
        dt = fpsGetDeltaTime();

        secu = majPosition(&Ball_v,dt)
        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calcul�e pour la balle
        sdl_setBallPosition(Balle_v.position.x,Balle_v.position.y);

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}

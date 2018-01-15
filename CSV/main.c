//
//  main.c
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#include <stdlib.h>
#include <stdio.h>
#include "vecteur.h"
#include "balle.h"

int main()
{

    Balle Balle_v;

    Balle_v = chargerBalle;

    printf("%f\n%f\n%f %f\n%f %f\n", Balle_v.masse, Balle_v.coeffriction, Balle_v.position.x, Balle_v.position.y, Balle_v.vitesse.x, Balle_v.vitesse.y);
    
}

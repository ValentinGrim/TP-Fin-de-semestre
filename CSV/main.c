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

int main(int agrc, char ** argv)
{

    if (agrc < 2) return EXIT_FAILURE;

    Balle Balle_v;
    Balle_v = chargerBalle(argv[1]);

    FILE *pFichier = NULL;
    pFichier = fopen(argv[2], "w");



    for(float t = 0.0; t <= 3; t += 0.01)
    {
        int secu;
        fprintf(pFichier, "%f;%f;%f\n", t, Balle_v.position.x, Balle_v.position.y);
        secu = majPosition(&Balle_v, 0.01);
        if(secu == -1) return EXIT_FAILURE;



    }

    fclose(pFichier);

}

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
    Balle_v = chargerBalle();

    majPosition(&Balle_v, 1);


}

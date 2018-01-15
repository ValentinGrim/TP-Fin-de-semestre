//
//  balle.h
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#ifndef balle_h
#define balle_h

#include "vecteur.h"

typedef struct Balle_decl
{

  float masse; //Kilo
  float coeffriction;
  Vecteur position; //m
  Vecteur vitesse; // m/s
  Vecteur acceleration; // m/s2

} Balle;

Balle chargerBalle(char * chemin);



#endif /* balle_h */

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
  struct Balle_decl * ballePrecedente;
  struct Balle_decl * balleSuivante;
} Balle;

Balle chargerBalle(char * argc);


int majPosition(Balle * Balle ,float dt);     // Met a jour la position de la balle en appliquant le PFD
                                              //retourne -1 si balle est NULL (securite)



#endif /* balle_h */

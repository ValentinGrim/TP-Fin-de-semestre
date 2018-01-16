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

typedef struct AttracteurList_decl
{

	Vecteur positionAttracteur[5];
	int utiliseMoi [5];

}AttracteurList;

Balle chargerBalle(char * argc);

int majPosition(Balle * Balle, AttracteurList * pAttrList ,float dt);     // Met a jour la position de la balle en appliquant le PFD

void initAttracteurList(AttracteurList * pAttrList);

#endif /* balle_h */

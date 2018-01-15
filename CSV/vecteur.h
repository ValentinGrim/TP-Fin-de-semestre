//
//  vecteur.h
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#ifndef vecteur_h
#define vecteur_h
typedef struct Vecteur_decl
{
	float x;
	float y;
} Vecteur;

Vecteur creerVect(float x,float y);

Vecteur multScalVEct(float s, Vecteur v);

Vecteur addVect(Vecteur v1, Vecteur v2);


#endif /* vecteur_h */

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

Vecteur multScalVect(float s, Vecteur v);

Vecteur addVect(Vecteur v1, Vecteur v2);


// Normalise le vecteur v
Vecteur normaliseVect(Vecteur v);

// Calcule la norme du vecteur v5
float normVect(Vecteur v);


// Soustrait 2 vecteurs et retourne le resultat
Vecteur subVect(Vecteur v1, Vecteur v2);

#endif /* vecteur_h */

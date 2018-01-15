//
//  balle.c
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#include "balle.h"
#include "vecteur.h"
#include <stdlib.h>
#include <stdio.h>

Balle chargerBalle()
{

  Balle Balle_v;

  FILE *pFichier = NULL; //init pointeur fichier NULL

  pFichier = fopen("balle.txt", "r"); //Ouverture fichier texte

  fscanf(pFichier, "masse %f\n", &Balle_v.masse); //Récupérer Valeur masse
  fscanf(pFichier, "fCoef %f\n", &Balle_v.coeffriction); //Récuperer Valeur fcoef
  fscanf(pFichier, "position %f %f\n", &Balle_v.position.x, &Balle_v.position.y); //Récupérer valeur position en x et y
  fscanf(pFichier, "vitesse %f %f", &Balle_v.vitesse.x, &Balle_v.vitesse.y); // Récupérer valeur vitesse en x et y

  fclose(pFichier);

  return Balle_v;

}


int majPosition(Balle * balle, float dt)          // Met a jour la position de la balle en appliquant le PFD et retourne -1 si balle est NULL (securite) retourne -1 si balle est NULL (securite)
{

  Balle Balle_v;
  Balle_v = chargerBalle();

  Vecteur P;                                      // Création du vecteur poids
  P = creerVect(0,-9.81);
  P = multScalVect(Balle_v.masse,P);

  Vecteur f;                                      // Création du vecteur des forces de frottements fisqueux
  f = Balle_v.vitesse;
  f = multScalVect(Balle_v.coeffriction,f);

  Vecteur S;                                       // Le vecteur de la somme des forces
  S = addVect(P,f);

  Balle_v.acceleration = multScalVect((1/Balle_v.masse),S);
}

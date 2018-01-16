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

Balle chargerBalle(char * chemin)
{

  Balle Balle_v;

  FILE *pFichier = NULL; //init pointeur fichier NULL

  pFichier = fopen(chemin, "r"); //Ouverture fichier texte

  fscanf(pFichier, "masse %f\n", &Balle_v.masse); //Récupérer Valeur masse
  fscanf(pFichier, "fCoef %f\n", &Balle_v.coeffriction); //Récuperer Valeur fcoef
  fscanf(pFichier, "position %f %f\n", &Balle_v.position.x, &Balle_v.position.y); //Récupérer valeur position en x et y
  fscanf(pFichier, "vitesse %f %f", &Balle_v.vitesse.x, &Balle_v.vitesse.y); // Récupérer valeur vitesse en x et y

  fclose(pFichier);

  return Balle_v;

}


int majPosition(Balle * Balle_v, float dt)          // Met a jour la position de la balle en appliquant le PFD et retourne -1 si balle est NULL (securite) retourne -1 si balle est NULL (securite)
{

  if (!Balle_v) return -1;

  else
  { 

    Vecteur P;                                      // Création du vecteur poidss
    P = creerVect(0,-9.81);
    P = multScalVect(Balle_v->masse,P);

    Vecteur f;                                      // Création du vecteur des forces de frottements fisqueux
    f = multScalVect(-Balle_v->coeffriction,Balle_v->vitesse);

    Vecteur S;                                       // Le vecteur de la somme des forces
    S = addVect(P,f);

    Balle_v->acceleration = multScalVect(((float)1/Balle_v->masse),S);     //calcul de l’accélération courante grâce à l’équation (1)

    Balle_v->vitesse = addVect(Balle_v->vitesse,(multScalVect(dt , Balle_v->acceleration)));	// Calcul de la nouvelle vitesse grâce à l'équation (2)

    Balle_v->position = addVect(Balle_v->position,(multScalVect(dt , Balle_v->vitesse))); //Calcul de la nouvelle position grâce a l'équation (3)

    return 0;

  }

}

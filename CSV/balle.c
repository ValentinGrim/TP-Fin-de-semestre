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
  Vecteur tmp;

  Balle_v = chargerBalle();

  Vecteur P;                                      // Création du vecteur poidss
  P = creerVect(0,-9.81);
  P = multScalVect(Balle_v.masse,P);

  Vecteur f;                                      // Création du vecteur des forces de frottements fisqueux
  f = Balle_v.vitesse;
  f = multScalVect(Balle_v.coeffriction,f);

  Vecteur S;                                       // Le vecteur de la somme des forces
  S = addVect(P,f);

  tmp = Balle_v.vitesse; // Sauvegarde de la vitesse pour majPosition

  Balle_v.acceleration = multScalVect((1/Balle_v.masse),S);     //calcul de l’accélération courante grâce à l’équation (1)

  Balle_v.acceleration = multScalVect(dt , Balle_v.acceleration); 	//Mise jour de l'acceleration pour l'équation (2) = a(t)dt
  Balle_v.vitesse = addVect(Balle_v.vitesse,Balle_v.acceleration);	// Calcul de la nouvelle vitesse grâce à l'équation (2)

  tmp = multScalVect(dt , tmp); //Mise a jour de la vitesse pour l'équation (3) = v(t)dt
  Balle_v.position = addVect(Balle_v.position, tmp);

}

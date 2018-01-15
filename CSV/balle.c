//
//  balle.c
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#include "balle.h"
#include <stdio.h>

Balle chargerBalle(char * chemin)
{
  
  Balle Balle_v;

  FILE *pFichier = NULL; //init pointeur fichier NULL

  pFichier = fopen("balle.txt", "r"); //Ouverture fichier texte

  fscanf(pFichier, "masse %f\n", &Balle_v.masse); //Récupérer Valeur masse
  fscanf(pFichier, "fCoef %f\n", &Balle_v.coeffriction); //Récuperer Valeur fcoef
  fscanf(pFichier, "position %f %f\n", &Balle_v.position.x, &Balle_v.position.y); //Récupérer valeur position en x et y
  fscanf(pFichier, "vitesse %f %f", &Balle_v.vitesse.x, &Balle_v.vitesse.y); // Récupérer valeur vitesse en x et y
  
  fclose(pFichier);

}


intmajPosition(Balle * balle, float dt)          // Met a jour la position de la balle en appliquant le PFD et retourne -1 si balle est NULL (securite) retourne -1 si balle est NULL (securite)
{
  
  
  
}


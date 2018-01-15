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
  char c; //Buffer de lecture a vide

  FILE *pFichier = NULL; //init pointeur fichier NULL

  pFichier = fopen(chemin, "r"); //Ouverture fichier texte

  fread(&c, sizeof(char), 6, pFichier); //Passe le mot "masse "
  //fscanf(pFichier, "%f", &Balle.masse); //Récuperer la valeur de la masse

}

int main()
{

  char c; //Buffer de lecture a vide

  Balle Balle_v;

  FILE *pFichier = NULL; //init pointeur fichier NULL

  pFichier = fopen("balle.txt"), "r"); //Ouverture fichier texte

  fread(&c, sizeof(char), 6, pFichier); //Passe le mot "masse "
  fscanf(pFichier, "%f", &Balle_v.masse); //Récuperer la valeur de la masse

  printf("%f", Balle_v.masse);

  fclose(pFichier);

}

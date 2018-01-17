//
//  main.c
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#include <stdlib.h>
#include <stdio.h>
#include "vecteur.h"
#include "balle.h"

int main(int agrc, char ** argv)
{

    if (agrc < 3) //test des arguments entrée de le min quitter s'il n'y en a pas assez.
    {

      printf("Il manque un ou plusieurs arguments.");
      return EXIT_FAILURE; // On quitte le programme

    }

    Balle Balle_v; // Déclaration dela balle principale
    Balle_v = chargerBalle(argv[1]); //Chargement de la balle avec les configuration comprise dans le fichier texte

    FILE *pFichier = NULL; //Déclaration pointeur fichier
    pFichier = fopen(argv[2], "w"); //ouverture csv et assignation du pointeur fichier

    float t; //Variable de temps

    for(t = 0.0; t <= 3; t += 0.01) // Boucle de caclule de nouvelle position de la balle
    {
        int secu; //Variable de sécuratié pour Balle null
        fprintf(pFichier, "%f;%f;%f\n", t, Balle_v.position.x, Balle_v.position.y); //Ecriture de la position de la balle et du temps dans le csv
        secu = majPosition(&Balle_v, 0.01); // Mise a jours avec les nouvelle coordonées, vitese et...
        if(secu == -1) return EXIT_FAILURE; //Sécurité



    }

    fclose(pFichier);
    return 0;
}

//
//  main.c
//  CSV
//
//  Created by Valentin Monnot / Josselin Pichereau on 15/01/2018.
//  Evalution TP Final
//

#include <stdlib.h>
#include <stdlib.h>

int main()
{
    
    char c;
    unsigned long res;
    
    FILE *pFichier = NULL; //Créa pointeur fichier
    
    pFichier = fopen("balle.txt", "r"); //Ouverture du fichier balle.txt
    
    do
    {
        
        res = fread(&c, sizeof(char), 1, pFichier);
        printf("%c",c);
        
    }
    while(res > 0);
    
    fclose(pFichier);
    
}


/* 12.1 (∗) Écrire une fonction qui lit un entier n au clavier, alloue un tableau de n
entiers initialisés à 0, et retourne n et le tableau.*/
#include <stdio.h>
#include <stdlib.h> //permet l'usage de la fonction malloc()

int* myfunction(int *tabSize) // myfunction() return le tableau (le pointeur)
{   
    int tailleTab ;// equivalent tabZise : taille tableau
    int  i; // i indice 
    int *tableau; //pointeur vers un tableau (qui sera return explicitement)
    
    printf("Entrez le nombre d'elt du tableau ");
    scanf("%d", &tailleTab);
    *tabSize= tailleTab ; //*tabSize = tailleTab; //taille tableau en pointeur car on veux faire un passage param par adresse)
    tableau = (int*) malloc(tailleTab*sizeof(int)); // allocation memeoire autableau
    for ( i = 0; i < tailleTab; i++) // initialisation des elt du tab a 0
    {
        tableau[i]=0;
    }
    return tableau;  // myfunction() return le tableau (le pointeur)
}

void main ()
{   int i;
    int tabSize;
    int *tableau;
    tableau = myfunction(&tabSize); // myfunction() return le tableau
    for ( i = 0; i < tabSize; i++)
    {
        printf("indice tableau %d: %d \n", i, tableau[i]);
    }
    free(tableau); /* libération de mémoire obligatoire */

    return;
}
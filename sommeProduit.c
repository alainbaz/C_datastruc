/*11.5 (∗) Écrire une fonction qui calcule la somme et le produit des éléments d’un
tableau passé en paramètre. Écrire le programme principal qui initialise le tableau par
saisie ; calcule et affiche la somme et le produit des éléments.*/
#include <stdio.h>
#define taille 5

void somme_produit (int tab[], int nbreElt, int *somme, int *produit) 
{ //les pointeur car on souhaire leur modifier directement 
   // int somme, produit;
   int i;
    *somme= 0;
    i=0;
    for ( i = 0; i < nbreElt; i++) // computing of sum
    {
        *somme+= tab[i];/* code */
    }

    *produit=1;
    i=0;
    for ( i = 0; i < nbreElt; i++) //  cmputing of product
    {
        *produit=*produit*tab[i];/* code */
    }
}

int main ()
{
    int tab[taille];
    int i;
    int somme, produit;
    for ( i = 0; i < taille; i++)
    {
        printf("Entrez l'element du tableau N° %d ", i) ;/* code */
        scanf("%d", &tab[i]);
    }
    somme_produit(tab, taille, &somme, &produit);
    printf ("Somme= %d \n Produit= %d \n", somme, produit);
    return 0;
}
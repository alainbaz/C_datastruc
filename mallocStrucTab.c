/* 12.4 (∗∗) Considérons la structure TypeTableau suivante qui contient l’adresse
d’un tableau et le nombre d’éléments du tableau.
typedef struct{
    int nb_elem; //* nombre d’éléments 
    int *tab; //* tableau 
}TypeTableau;
a) Écrire une fonction de prototype
TypeTableau CreationTableau(int n);
qui crée un tableau de n éléments. */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int nb_elem; //* nombre d’éléments 
    int *tab; //* tableau 
}TypeTableau;

TypeTableau CreationTableau(int n)
{
    TypeTableau tableau;
    tableau.nb_elem = n; //attribution de la taille du tableau recu a nbre_elt
    tableau.tab = malloc(n*(sizeof(int))); //allocation mem à la taille du tableau
    return tableau; // return pointeur tableau
}
/* b) Écrire une fonction de prototype
void DestructionTableau(TypeTableau T);
qui libère la mémoire occupée par un tableau. */
void DestructionTableau(TypeTableau T)
{
    int *tabLocal;
    tabLocal = T.tab;// chemin ers la taille du tableau
    //l'argument de la fx free() est de type pointeur
    free(tabLocal); /* libération de mémoire obligatoire */  
}

/* c) Écrire une fonction de prototype
void SimpleLectureTableau(TypeTableau T);
qui lit les éléments d’un tableau au clavier. On supposera dans cette fonction que le
tableau a déja été alloué précédemment. */

TypeTableau SimpleLectureTableau(TypeTableau T)
{
   int tailleLocal, i;
   TypeTableau maStruc; 
    tailleLocal=T.nb_elem;// chemin ers la taille du tableau 
    printf("Bienvenue!");
   for ( i = 0; i < tailleLocal; i++)
   {
       printf("Entrez elt N° %d \n", i);
       scanf("%d",&T.tab[i]);
   }
    maStruc.tab = T.tab;
    return maStruc;
}
/* d) Écrire une fonction de prototype
void Affichage(TypeTableau T);
qui affiche le contenu d’un tableau. */
void Affichage(TypeTableau T)
{   
    int tailleLocal, i;
    tailleLocal = T.nb_elem;// chemin ers la taille du tableau 
   printf("votre super tableau est : \n") ;
   for ( i = 0; i < tailleLocal; i++)
   {
       printf("%d \n", T.tab[i] );
   }
}
/* e) Écrire une fonction de prototype
TypeTableau DoubleTableau(TypeTableau T);
qui crée un nouveau tableau de même taille que T mais dont les éléments sont le
double des éléments de T. */
TypeTableau DoubleTableau(TypeTableau T)
{
   TypeTableau TabDouble ;
   int i , tailleLocal; 
   tailleLocal = T.nb_elem; // chemin ers la taille du tableau 
   for ( i = 0; i < tailleLocal; i++)
   {
       TabDouble.tab[i] = 2*(T.tab[i]); //compute double of each elementof tab 
   }
   return TabDouble;
}
/* f) Écrire un programme principal qui saisit un tableau au clavier, calcule le double de
chaque élément du tableau et affiche les résultats. */
void main()
{
    TypeTableau maStruc;
    int tailleLocal;
    printf("Veuillez entrez le nombre d'elt du tableau ");
    scanf("%d", &tailleLocal);

    maStruc = CreationTableau(tailleLocal); //creatin allocatin memoir au tableau
    SimpleLectureTableau(maStruc); //saisi des elt du tableau
    Affichage(maStruc);// affichage du tableau saisi

    TypeTableau TabDouble ; //struc devant contenir le double a calculer
    TabDouble = CreationTableau(tailleLocal); //creatin allocatin memoir au tableau devant contenir le double
    DoubleTableau(maStruc);//calcal du double du tableau
    Affichage(TabDouble);// affichage du double calculé

    DestructionTableau(maStruc); // destrction du tab
    DestructionTableau(TabDouble) ; // destrction du tab
    return;
}
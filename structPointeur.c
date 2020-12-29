/*11.6 (∗∗) Soit une structure Point contenant deux champs x et y de type float.
a) Écrire une fonction qui échange deux structures Point passées par adresse.
b) Écrire le programme principal qui saisit deux structures Point dans des variables,
échange le contenu de ces variables en appelant la fonction et affiche le nouveau
contenu des variables.*/
#include <stdio.h>

typedef struct structPointeur  // definition de notre structure 
{
    float x;
    float y;
}point; // nom qui sera utilisé pour declarer des odjet de ce type a la façon  int x ou float y

void exchange( point *A , point *B)
{
    point i; //structure de transition 
    i.x = A ->x; 
    i.y = A ->y;
    //copie de B sur A
    A->x = B->x;
    A->y = B->y; 
    // copie de A (i) sur B
     B->x = i.x;
    B->y = i.y;
}

void main ()
{
    point A, B; 
    printf("Entrez A.x  ");
    scanf("%f", &A.x);
    printf("Entrez A.y  " );
    scanf("%f", &A.y);
     printf("Entrez B.x  ");
    scanf("%f", &B.x);
     printf("Entrez B.y  ");
    scanf("%f", &B.y);

    exchange(&A, &B);
    printf ("Resultat\n A.X:%.f   A.y:%.f \n B.x: %.f   B.y: %.f \n", A.x, A.y, B.x, B.y);
    return;
}



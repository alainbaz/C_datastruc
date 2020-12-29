#include <stdio.h>
/* a) Écrire un programme qui saisit deux variables de type int, qui échange leur
contenu et qui affiche les nouvelles valeurs des variables.
b) On se propose de refaire la question a) en réalisant l’échange de valeurs à l’inté-
rieur d’une fonction. Écrire une fonction qui échange le contenu de deux variables
passées par adresse. Écrire le programme principal qui saisit deux variables, les
échange en appelant la fonction et affiche le nouveau contenu des variables.
 */

int permut(int *x, int *y)
{  // qui échange leur contenu
    int c; 
    c=*x;
    *x=*y;
    *y=c;
}

int main()
{
int a, b;
printf("A: \n");
 scanf("%d", &a); //saisit deux variables de type int,
printf("B: \n"); 
scanf("%d", &b);
permut(&a,&b);
 printf("maintenant A: %d  B: %d\n", a,b); // affiche les nouvelles valeurs des variables
}
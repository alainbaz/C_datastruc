#include <stdio.h>
//*il faut passer en paramètre non pas la variable, mais un pointeur qui pointe sur la variable.
void NeModifiePas(int *x)
{
    *x +=10; /* le x local est modifié localement , et dans le x du main*/
}
int main(void)
{
    int x=1;
    int *p;
    p=&x;
    NeModifiePas(p);
    printf("x vaut : %d\n", x); /* affiche 11 : valeur de x inchangée */
    return 0;
}

/* int main(void)
{
    int x=1;
    Modifie(&x); //* on passe directement l’adresse de x 
    printf("%d", x); //* affiche 2 
    return 0;
} */
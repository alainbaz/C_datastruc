/* 1.1 (∗) Écrire une fonction qui initialise deux entiers et un réel à 0. Écrire le pro-
gramme principal qui appelle cette fonction. */
#include <stdio.h>
int initialise(int *x, int *y, float *z)
{
    *x =0;
    *y=0;
    *z=0;
    
}

int main ()
{
    int x, y;
    float z; 
    initialise(&x,&y,&z);
    printf("xyz : %d %d %.f", x,y,z);
}
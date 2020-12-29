#include <stdio.h>
int main(void)
{
    int x = 2;
    int *p ;
    p= &x; /* x et *p deviennent synonymes */

    printf("La nouvelle valeur de x est %d\n", *p);
    /* doit afficher la valeur 3 */
    return 0;
}
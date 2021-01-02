/*12.2 (∗) On se propose de réaliser une fonction de chargement en mémoire centrale
sous forme de tableau de float d’un fichier texte. Le format de fichier est le suivant :
• la première ligne du fichier contient le nombre d’éléments du tableau ;
• les lignes suivantes contiennent chacune un nombre réel.
n
f_1
f_2
...
f_n
a) Réaliser une fonction de chargement dans un tableau dont la taille mémoire cor-
respond exactement au nombre d’éléments du fichier.
b) Réaliser une fonction d’affichage du tableau.
c) Écrire le programme principal qui charge le fichier et affiche le tableau.*/
#include <stdio.h>
#include <stdlib.h>
#define taille_max_tableau 100

float* chargementTableau (int *tabSize) // fx de chargement tableau return *float car return un flottant (le pointeur vers un tableau)
{   int tailleTabLocal;// taille tab local pour eviter le pointeur
    float *tableau; //pointeur du talbeau qui recevra les donnéed issu du fichier.txt
    int i ; // indice tableau
    FILE *fp; //un pointeur de type fichier.txt
    fp = fopen("fichierMalloc.txt", "r+"); // on donne le chemin du fichier, la fx d'ouverture
                                             // et le mode de lecture r+ (lecture)
    if (fp== NULL)
    {
        printf("Erreur de lecture du fichier\n");/* virification du fichier texte*/
    }
    fscanf(fp, "%d", &tailleTabLocal); // la 1ere ligne du fichier contient le nbre total de ligne (taille du tableau)
    tableau = (float*) malloc(tailleTabLocal*sizeof(float)); // allocation de memoire à la taille lue du tableau
    for ( i = 0; i < tailleTabLocal; i++)
    {
        fscanf(fp, "%f", &tableau[i]);/* code */
    }
   /* 
    while (fscanf(fp, "%f", &tableau[i]) == 1)  // lecture des donnée et copie dans le tableau
    {
       i++; 
    } 
    */
    *tabSize= tailleTabLocal; // tabSize comme var globale est modif car passé par adresse
    fclose(fp);

    return tableau;   // return le tableau via le pointeur vers celui ci)
} 

int affichageTab(int *tabSize, float *tableau)  
{   int i; //indice tableau
    int tailleLocal; //taille tab pour travailler dans la fonction
    //float *tableau ; //pointeur vers un tableau (qui sera return explicitement)
    // *tabSize est modifié car passé par adresse
    tailleLocal = *tabSize; // car on ne sait pas passer un pointeur dans une boucle jusque là
    printf("Nbre ligne: %d \n", *tabSize); //  pas dans la boucle a été lu separement en premier
    for ( i = 0; i < tailleLocal-1; i++) // -1 car la 1ere ligne (nbre d'elt) a deja été lue
    {
        printf("Tableau: \n %.0f \n", tableau[i]);   // affichage du tableau
    }
    return 0;  
}


void main()
{   float *tableau; // declaration du pointeur vers un tableau
    int tabSize; 
    tableau = chargementTableau(&tabSize); // chargement des donnee en memoire
    affichageTab(&tabSize, tableau); /*  parametre tableau est passé par adresse certe mais sans
    le (*) car il s'agit deja d'une adresse des sa declaration */
    free(tableau); /* libération de mémoire obligatoire */
    return; 
}
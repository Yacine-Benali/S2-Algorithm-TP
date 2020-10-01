#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;

void transformation(Liste *tete)
{
    Liste *courant = tete;
    while (courant->suiv != NULL) // Parcourir la liste et s'arrêter sur le dernier élément
        courant = courant->suiv;
    courant->suiv = tete; // Mettre la valeur de tete dans le suivant du dernier élément
}

void affichListe_circ(Liste *tete)
{
    Liste *p = tete;
    if (p == NULL)
         printf("Rien a afficher, la liste est vide!");
    else
        do
        {
            printf("%d ", p->valeur);
            p = p->suiv;

        } while (p != tete);
    printf("\n");
}
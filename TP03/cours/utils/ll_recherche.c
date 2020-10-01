#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;

Liste *recherche(Liste *tete, int val)
{
    Liste *courant = tete;
    while (courant != NULL) // Parcours de la liste
    {
        if (courant->valeur == val)
            return courant;
        courant = courant->suiv;
    }
    return NULL; // Liste épuisée et val introuvable
}
#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;
Liste *supprimer_liste(Liste *tete)
{
    Liste *p;
    while (tete != NULL)
    {
        p = tete;
        tete = tete->suiv;
        free(p); // libérer l'espace alloué
    }
    return NULL;
}

Liste *suppression(Liste *tete, int val)
{
    Liste *cour, *prec;
    /* Le pointeur cour est le pointeur courant et le pointeur prec sert à mé
    moriser l'adresse de l'élément précédent */
    // La valeur val se trouve en tête de liste
    if (tete->valeur == val)
    { // Le deuxième élément devient tête de liste
        prec = tete;
        // Suppression de l'espace alloué
        tete = tete->suiv;
        free(prec);
    }
    else
    { // Sinon parcours de la liste à partir du début pour localiser val
        prec = tete;
        cour = tete->suiv;
        while (cour != NULL && cour->valeur != val)
        {
            prec = cour;
            cour = cour->suiv;
        }
        if (cour == NULL)
            printf("La valeur n'existe pas!\n");
        else
        {
            prec->suiv = cour->suiv; // La valeur val est trouvée à la position indiquée par cour
            free(cour);
        }
    }
    return tete;
}
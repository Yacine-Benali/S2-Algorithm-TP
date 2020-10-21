#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;

Liste *tete1 = NULL;
Liste *tete2 = NULL;
Liste *tete3 = NULL;
Liste *creation(Liste *tete, int x); // La fonction retourne un pointeur de type Liste
void affichListe(Liste *tete);
Liste *fusion(Liste *tete1, Liste *tete2);

int main()
{
    tete1 = creation(tete1, 1);
    tete1 = creation(tete1, 3);
    tete1 = creation(tete1, 9);
    printf("\nContenu de la liste 1 :\n");
    affichListe(tete1);
    //
    tete2 = creation(tete2, 2);
    tete2 = creation(tete2, 4);
    tete2 = creation(tete2, 8);
    printf("\nContenu de la liste 2 :\n");
    affichListe(tete2);
    //
    tete3 = fusion(tete1, tete2);
    printf("\nContenu de la liste 3 :\n");
    affichListe(tete3);
}
Liste *fusion(Liste *tete1, Liste *tete2)
{
    Liste *tete;
    Liste *cour, *cour1, *cour2;       // Le pointeur cour parcourt la liste résultat
    cour1 = tete1;                     // Le pointeur cour1 parcourt la première liste dont la tete est tete1
    cour2 = tete2;                     // Le pointeur cour2 parcourt la deuxième liste dont la tete est tete2
    if (tete2->valeur > tete1->valeur) //La valeur du pointeur tete est soit tete1 soit tete2
    {
        tete = tete1;
        cour = tete;
        cour1 = tete1->suiv;
    }
    else
    {
        tete = tete2;
        cour = tete;
        cour2 = tete2->suiv;
    }
    // Ayant obtenu l'élément en tête, construire le reste de la liste
    while (cour1 != NULL && cour2 != NULL)
        if (cour2->valeur > cour1->valeur)
        {
            cour->suiv = cour1;
            cour = cour1;
            cour1 = cour1->suiv;
        }
        else
        {
            cour->suiv = cour2;
            cour = cour2;
            cour2 = cour2->suiv;
        }
    // Si la première est épuisée alors chaîner ce qui reste de la
    if (cour1 == NULL && cour2 != NULL)
        cour->suiv = cour2;
    else
        cour->suiv = cour1;
    return tete;
}

Liste *creation(Liste *tete, int x)
{
    Liste *p = (Liste *)malloc(sizeof(Liste)); /* Ou bien Liste *p = new Liste tout simplement en
utilisant l'opérateur new du C++ */
    p->valeur = x;
    p->suiv = tete;
    return p; // Nouvelle tête
}

void affichListe(Liste *tete)
{
    Liste *courant = tete;
    if (courant == NULL)
        printf("Rien a afficher, la liste est vide!\n");
    else
        while (courant != NULL)
        {
            printf("%d ", courant->valeur);
            courant = courant->suiv;
        }
    printf("\n");
}

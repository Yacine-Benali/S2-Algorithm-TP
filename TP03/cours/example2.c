#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;
    struct liste *suiv;
} Liste;
Liste *tete = NULL;
Liste *creation(Liste *tete, Liste **queue, int x); /* Passage par adresse du pointeur queue de
liste */
void affichListe(Liste *tete);
main()
{
    int x;
    char reponse = 'o';
    Liste *queue; // Pointeur sur le dernier élément de la liste
    do
    {
        printf("Entrer la valeur : ");
        scanf("%d", &x);
        //Actualisation de la valeur de tete et récupération de la valeur de queue
        tete = creation(tete, &queue, x);
        printf(" Voulez vous continuer o/n ? : ");
        fflush(stdin); /*Vider le buffer en cas de non lecture de la réponse */
        reponse = getchar();
    } while (reponse == 'o');
    if (queue != NULL)
        queue->suiv = NULL; // Marquer la fin de la liste
    printf("\nContenu de la liste :\n");
    affichListe(tete);
}
Liste *creation(Liste *tete, Liste **queue, int x)
{
    Liste *p = (Liste *)malloc(sizeof(Liste));
    p->valeur = x;
    p->suiv = NULL;
    if (tete == NULL) // Si la liste est vide, le nouvel élément devient tête de liste
        tete = p;
    else
        (*queue)->suiv = p; /* Sinon le nouvel élément est chaîné au dernier élément de la liste */
   
    *queue = p;             // Actualisation du pointeur queue qui devient le nouvel élément
    return tete;            // Nouvelle tête si la liste était réellement vide
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

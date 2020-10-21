#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;

Liste *tete = NULL;
Liste *creation(Liste *tete, int x); // La fonction retourne un pointeur de type Liste 
void affichListe(Liste *tete);

int main()
{
    int x;
    char reponse = 'o'; // Réponse à la question : Voulez vous continuer (oui/non)?
    do
    {
        printf("Entrer la valeur : ");
        scanf("%d", &x);
        tete = creation(tete, x); // Actualisation de la valeur de tete
        printf(" Voulez vous continuer o/n ? : ");
        fflush(stdin); // Vider le buffer (mémoire tampon) en cas de non lecture de la réponse
        reponse = getchar();

    } while (reponse == 'o');
    printf("\nContenu de la liste :\n");
    affichListe(tete);
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

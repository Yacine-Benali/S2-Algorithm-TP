#include <stdio.h>
#include <stdlib.h>
typedef struct liste
{
    int valeur;         // Champ donnée de l'élément
    struct liste *suiv; // Champ adresse pointant vers l'élément suivant
} Liste;
Liste *insert_tete(Liste *tete, int x); // La fonction retourne un pointeur de type Liste
void affichListe(Liste *tete);
Liste *insert_queue(Liste *tete, int x);
Liste *insert_indice(Liste *tete, int x, int l);
Liste *insert_address(Liste *tete, Liste *p, int x);
int main()
{
    int x;
    Liste *tete = NULL;

    char reponse = 'o'; // Réponse à la question : Voulez vous continuer (oui/non)?
    do
    {
        printf("Entrer la valeur : ");
        scanf("%d", &x);
        tete = insert_queue(tete, x); // Actualisation de la valeur de tete
        printf(" Voulez vous continuer o/n ? : ");
        fflush(stdin); // Vider le buffer (mémoire tampon) en cas de non lecture de la réponse
        reponse = getchar();

    } while (reponse == 'o');
    tete = insert_indice(tete, 69, 2);
    printf("\nContenu de la liste :\n");
    affichListe(tete);
}

Liste *insert_tete(Liste *tete, int x)
{
    Liste *nouv = (Liste *)malloc(sizeof(Liste));
    //Saisir les informations
    nouv->valeur = x;
    //Chaînage du nouvel élément à la liste
    nouv->suiv = tete; //Le premier élément devient deuxième et ainsi de suite

    return nouv; // La nouvelle valeur de tete c'est nouv
}
Liste *insert_queue(Liste *tete, int x)
{
    // Declaration d 'un deuxième pointeur sur l'élément courant
    Liste *courant;
    //Création d'un nouveau noeud
    Liste *nouv = (Liste *)malloc(sizeof(Liste));
    //Saisir les informations
    nouv->valeur = x;
    nouv->suiv = NULL;
    if (tete == NULL)
        tete = nouv;
    else
    {
        // Se positionner sur le dernier élément
        courant = tete;
        while (courant->suiv != NULL)
            courant = courant->suiv;
        //Chaînage du nouvel élément à la liste
        courant->suiv = nouv;
    }
    return tete; // Nouvelle valeur de tete au cas où la liste était vide
}

Liste *insert_indice(Liste *tete, int x, int l)
{
    //Compteur jusqu'à la valeur l
    int i;
    // adresses de l'élément précédent et de l'élément courant (les 2 futurs
    // voisins de l'élément nouv)
    Liste *prec, *courant;

    Liste *nouv = (Liste *)malloc(sizeof(Liste));
    //Saisir les informations
    nouv->valeur = x;
    if (l == 1)
    {
        nouv->suiv = tete;
        // La nouvelle tête de liste
        tete = nouv;
    }
    else
    { // Se positionner à la position l
        i = 1;
        courant = tete;
        while (courant != NULL && i < l)
        {
            prec = courant;
            courant = courant->suiv;
            i++;
        }
        if (i == l)
        {
            nouv->suiv = courant;
            prec->suiv = nouv;
        }
        else
            printf("La liste est trop courte pour insérer a la position %d\n", l);
    }
    return tete;
}

Liste *insert_address(Liste *tete, Liste *p, int x)
{
    //Création d'un nouveau noeud
    Liste *nouv = (Liste *)malloc(sizeof(Liste));
    //Saisir les informations
    nouv->valeur = x;
    if (p == NULL)
    {
        nouv->suiv = tete;
        tete = nouv; // La nouvelle tête de liste
    }
    else
    {
        nouv->suiv = p->suiv;
        p->suiv = nouv;
    }
    return tete;
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
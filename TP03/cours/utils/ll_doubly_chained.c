#include <stdio.h>
#include <stdlib.h>

typedef struct liste
{
    int val;
    struct liste *prec;
    struct liste *suiv;
} Liste;

Liste *creation(Liste *tete, int x);
int main()
{
    Liste *tete = creation(tete, 5);
}

Liste *creation(Liste *tete, int x)
{
    Liste *p = (Liste *)malloc(sizeof(Liste));

    p->val = x;
    p->prec = NULL;
    p->suiv = tete;
    if (tete != NULL)
        tete->prec = p;
    return p; // Nouvelle tête
}

Liste *insertion(Liste *tete, Liste *p, int x)
{
    Liste *nouv = (Liste *)malloc(sizeof(Liste));
    nouv->val = x;
    nouv->prec = p;
    if (p == NULL)
    { // Insertion en tête de liste
        nouv->suiv = tete;
        if (tete != NULL)
            tete->prec = nouv;
        tete = nouv;
    }
    else
    {
        nouv->suiv = p->suiv;
        if (p->suiv != NULL)
            p->suiv->prec = nouv;
        p->suiv = nouv;
    }
    return tete;
}

void suppression(Liste *tete, int l)
/* Passage par adresse de tete au cas d'une éventuelle
modification */
{
    Liste *p;
    int i; // Compteur jusqu'à l
    if (tete == NULL)
        printf("<Rien a supprimer, la liste est vide!\n");
    else
    {
        if (l == 1)
        {
            p = tete;
            tete = tete->suiv;
            tete->prec = NULL;
        }
        else
        {
            i = 1;
            p = tete;
            while (p != NULL && i < l)
            {
                p = p->suiv;
                i++;
            }
            if (p != NULL)
            {
                p->suiv->prec = p->prec;
                p->prec->suiv = p->suiv;
            }
        }
        free(p);
    }
}

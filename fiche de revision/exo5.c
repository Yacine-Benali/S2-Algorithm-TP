#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int val;
    struct list *suiv;

} List;

int questionUn(List *tete)
{
    if (tete == NULL)
    {
        printf("la list est vide");
        return -1;
    }
    else
    {
        List *courant = tete->suiv;
        List *precedant = tete;
        int estCroissant = 1;
        while (courant != NULL)
        {
            if (precedant->val > courant->val)
            {
                printf("la list n'est pas tries\n");
                return 0;
            }
            precedant = courant;
            courant = courant->suiv;
        }
        return estCroissant;
    }
}

List *questionDeux(List *tete)
{
    if (tete == NULL)
    {
        printf("la list est vide\n");
    }
    else
    {
        List *courant = tete;
        List *precedant = tete;
        int temp;
        while (courant != NULL)
        {
            temp = precedant->val;
            precedant->val = courant->val;
            courant->val = temp;

            precedant = courant;
            courant = courant->suiv;
        }
    }
    return tete;
}
List *questionDeux2(List *tete)
{
    if (tete == NULL)
    {
        printf("la list est vide \n");
    }
    else
    {
        List *p, *q = NULL;
        while (tete != NULL)
        {
            p = tete;
            tete = tete->suiv;
            p->suiv = q;
            q = p;
        }
        return q;
    }
}

List *ajout(List *tete, int val)
{
    List *nouv = (List *)malloc(sizeof(List));
    if (nouv == NULL)
    {
        printf("j'ai pa pu crée un noeud!");
    }
    else
    {
        nouv->val = val;
        nouv->suiv = tete;
        return nouv;
    }
}

void affiche(List *tete)
{

    List *courant = tete;
    while (courant != NULL)
    {
        printf("%d, ", courant->val);
        courant = courant->suiv;
    }
}
int main()
{
    List *tete = NULL;

    for (int i = 10; i >= 0; i--)
    {
        tete = ajout(tete, i);
    }
    affiche(tete);
    printf("\n");
    if (questionUn(tete))
    {
        printf("la list est croissante fliping...\n");
        tete = questionDeux2(tete);
        affiche(tete);
        printf("\n");
    }
    else
    {
        printf("la list n'est pas tries\n");
    }
}
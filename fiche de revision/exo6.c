#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int val;
    struct list *suiv;

} List;
void affiche(List *tete)
{

    List *courant = tete;
    while (courant != NULL)
    {
        printf("%d, ", courant->val);
        courant = courant->suiv;
    }
}
void questionDeux(List **tete)
{
    if ((*tete) == NULL)
    {
        printf("rien a supprimer\n");
    }
    else
    {

        List *courant = (*tete);
        List *precedant = NULL;
        List *temp;

        while (courant != NULL)
        {
            if (courant->val < 0)
            {
                if (precedant == NULL)
                {
                    courant = courant->suiv;
                    (*tete) = courant;
                }
                else
                {
                    temp = courant;
                    precedant->suiv = courant->suiv;
                    //
                    courant = courant->suiv;
                    free(temp);
                }
            }
            else
            {
                precedant = courant;
                courant = courant->suiv;
            }
        }
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

int main()
{
    List *tete = NULL;

    for (int i = 5; i > -6; i--)
    {
        tete = ajout(tete, i);
    }

    for (int i = -5; i < 6; i++)
    {
        tete = ajout(tete, i);
    }
    affiche(tete);
    printf("\n\n");
    questionDeux(&tete);
    affiche(tete);
    printf("\n\n");
}
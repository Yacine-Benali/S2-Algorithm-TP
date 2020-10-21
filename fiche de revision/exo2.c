#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
    int val;
    struct list *suiv;
} List;

List *tete = NULL;

void multiply()
{
    if (tete == NULL)
    {
        printf("lalist est vide rien a multiplier");
        return;
    }
    else
    {
        int result = 1;
        List *courant = tete;
        while (courant != NULL)
        {
            result = result * (courant->val);
            courant = courant->suiv;
        }
        printf("le resultat est %d", result);
    }
}

void ajout(int val)
{
    List *nouv = (List *)malloc(sizeof(List));
    if (nouv == NULL)
    {
        printf("j'ai pa pu crée un noeud!");
        return;
    }
    else
    {
        nouv->val = val;
        nouv->suiv = tete;
        tete = nouv;
    }
}

void affiche()
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
    for (int i = 1; i < 11; i++)
    {
        ajout(i);
    }
    multiply();
    //affiche();
}
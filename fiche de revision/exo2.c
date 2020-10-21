#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
    int val;
    struct list *suiv;
} List;

List *tete = NULL;

int multiplyRecursive(List *node)
{
    //no recursive
    if (node == NULL)
    {

        return 1;
    }
    else
    {
        return node->val * multiplyRecursive(node->suiv);
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
    int a = multiplyRecursive(tete);
    printf("%d", a);
    //affiche();
}
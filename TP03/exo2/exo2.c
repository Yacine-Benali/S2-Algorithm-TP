#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *suiv;
} Node;

void ajout(Node **tete, int x)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->val = x;
    newNode->suiv = NULL;
    if (*tete == NULL)
    {
        *tete = newNode;
    }
    else
    {
        Node *courant = *tete;
        while (courant->suiv != NULL)
        {
            courant = courant->suiv;
        }
        courant->suiv = newNode;
    }
}

void affiche(Node **tete)
{
    Node *courant;

    courant = *tete;
    while (courant != NULL)
    {
        printf("%d, ", courant->val);
        courant = courant->suiv;
    }
}
void insert(Node **tete, int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = x;
    Node *prec, *suiv;
    suiv = prec = *tete;
    while (suiv->suiv != NULL)
    {
        prec = suiv;
        suiv = suiv->suiv;
        if (x < suiv->val)
        {
            newNode->suiv = suiv;
            prec->suiv = newNode;
            break;
        }
    }
}
int main()
{
    Node *tete = NULL;
    for (int i = 0; i < 5; i += 2)
    {
        ajout(&tete, i);
    }
    affiche(&tete);
    printf("\n");
    insert(&tete, 1);
    affiche(&tete);
}
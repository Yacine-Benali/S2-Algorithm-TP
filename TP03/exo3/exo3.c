#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *suiv;
    struct node *prec;
} Node;

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

void ajout(Node **tete, int x)
{
    Node *p = (Node *)malloc(sizeof(Node));

    p->val = x;
    p->prec = NULL;
    p->suiv = *tete;
    // if (*tete != NULL)
    //     (*tete)->prec = p;
}

int main()
{
    Node *tete;
    ajout(&tete, 0);

    // for (int i = 0; i < 5; i++)
    // {
    //     ajout(&tete, i);
    // }
    affiche(&tete);
}
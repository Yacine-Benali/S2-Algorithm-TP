#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node *suiv;
} Node;

void init(Node **tete)
{
    (*tete) = NULL;
}
void ajout(Node **tete, int x)
{
    Node *node = malloc(sizeof(Node));
    node->val = x;
    node->suiv = (*tete);
    (*tete) = node;
}

void ajout2(Node **tete, int x)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *courant;
    node->val = x;
    node->suiv = NULL;
    if (*tete == NULL)
    {
        *tete = node;
    }
    else
    {
        courant = *tete;
        while (courant->suiv != NULL)
        {
            courant = courant->suiv;
        }
        courant->suiv = node;
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
int main()
{
    Node *tete;
    int n;
    init(&tete);

    printf("atchou n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ajout2(&tete, i);
    }
    affiche(&tete);
}

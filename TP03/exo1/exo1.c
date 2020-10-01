#include <stdio.h>
#include <stdlib.h>

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

void question1(Node **tete)
{
    int pos = 0;
    int zero = 0;
    int neg = 0;
    Node *courant = *tete;
    if (*tete == NULL)
    {
        printf("ah hamouda lista ki sraleha\n");
    }
    else
    {
        while (courant != NULL)
        {
            if (courant->val > 0)
                pos++;
            else if (courant->val < 0)
                neg++;
            else
                zero++;
            courant = courant->suiv;
        }
        printf("pos: %d\t zero: %d\t neg: %d\t \n", pos, zero, neg);
    }
}

void question2(Node **tete, int x)
{
    if ((*tete)->val == x)
        printf("raha hena f l'add: %d \n", (*tete));
    else
        question2(&((*tete)->suiv), x);
}

void question3(Node **tete)
{
    int somme = 0;
    Node *courant = *tete;
    while (courant != NULL)
    {
        somme += courant->val;
        courant = courant->suiv;
    }
    printf("la somme de la list %d", somme);
}
int main()
{
    Node *tete = NULL;
    for (int i = -5; i < 6; i++)
    {
        ajout(&tete, i);
    }
    affiche(&tete);
    printf("\n");
    question1(&tete);
    question2(&tete, 0);
    question3(&tete);
}
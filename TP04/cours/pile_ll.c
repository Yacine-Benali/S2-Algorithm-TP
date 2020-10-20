#include <stdio.h>
#include <stdlib.h>

typedef struct pile
{
    int val;
    struct pile *suivant;
} Pile;
Pile *p = NULL;

void init(Pile **p)
{
    *p = NULL;
}

int pilevide(Pile *p)
{
    return (p == NULL);
}

int sommet(Pile *p)
{
    if (p != NULL)
        return p->val;
}

void empiler(Pile **p, int v)
{
    Pile *nouv;
    nouv = malloc(sizeof(Pile));
    nouv->val = v;
    nouv->suivant = *p;
    *p = nouv;
}

void depiler(Pile **p, int *v)
{
    if (*p != NULL)
    {
        *v = (*p)->val;
        Pile *d = *p; //? wait what
        *p = (*p)->suivant;
        free(d);
    }
}
#include <stdio.h>
#define taillemax 50

typedef struct pile
{
    int ind;
    int tab[taillemax];
} pile;

pile p;

void init(pile *p)
{
    p->ind = -1;
}

int pilevide(pile p)
{
    return (p.ind == -1);
}

int pilepleine(pile p)
{
    return (p.ind == taillemax - 1);
}

int sommet(pile p)
{
    if (p.ind >= 0)
        return p.tab[p.ind];
}

void empiler(pile *p, int v)
{
    //! normalement ndirou taillemax bark bela -1 ?
    if (p->ind < taillemax - 1)
    {
        p->ind = p->ind + 1;
        p->tab[p->ind] = v;
    }
}

void depiler(pile *p, int *v)
{
    //! *v 3elah alor que nejmou naksou m indice direct
    if (p->ind > -1)
    {
        *v = p->tab[p->ind];
        p->ind = p->ind - 1;
    }
}
//! wtf
int rechinsert(pile *p, int val)
{
    pile p1;
    int v, bool = 1;
    init(&p1);
    while (pilevide(*p) == 0 && sommetpile(*p) > val)
    {
        depiler(p, &v);
        empiler(&p1, v);
    }
    if (pilevide(*p) || sommetpile(*p) < val)
    {
        empiler(p, val);
        bool = 0;
    }

    while (pilevide(p1) == 0)
    {
        depiler(&p1, v);
        empiler(p, v);
    }
    return bool;
}
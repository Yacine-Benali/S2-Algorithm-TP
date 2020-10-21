#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TailleMax 100 //Taille de la file figée \
                      // Déclaration de la structure File
typedef struct
{
    int Element[TailleMax]; /* Tableau de cases où chaque case est un élément de la pile */
    int queue;              /* Indice de la fin du tableau qui vaut -1 si la file est vide et TailleMax-1 si la file est pleine*/

} File;

void initFile(File *f)
{ /* Passage par adresse du paramètre f pour récupérer la nouvelle file f
après modification */
    (*f).queue = -1;
}

bool fileVide(File f)
{
    return (f.queue == -1);
}

bool filePleine(File f)
{
    return (f.queue == TailleMax - 1);
}

int TeteDeFile(File f)
{
    return f.Element[0];
}

int QueueDeFile(File f)
{
    return f.Element[f.queue];
}

void enfiler(File *f, int v)
{
    if (!filePleine(*f))
    {
        (*f).queue = (*f).queue++;
        (*f).Element[(*f).queue] = v;
    }
}

void defiler(File *f, int *v)
{
    int i;
    if (!fileVide(*f))
    {
        *v = (*f).Element[0];
        for (i = 0; i < (*f).queue; i++)
            (*f).Element[i] = (*f).Element[i + 1];
        (*f).queue = (*f).queue--;
    }
}
void affichFile(File f)
{
    int i;
    for (i = 0; i <= f.queue; i++)
        printf("\t\t%d\n", f.Element[i]);
}
#include <stdio.h>

int main()
{
    FILE *file;

    file = fopen("essai1.dat","r");

    if(file == NULL)
    {
        printf("Erreur d'ouverture du fichier en lecture !\n");
        return -1;
    }
    char c;
    int compteur = 0;
     while ((c = fgetc(file)) != EOF)
    {
        printf("%c \n",c);
        compteur++;
    }
    printf("le nombre de characatere est %d",compteur);
}
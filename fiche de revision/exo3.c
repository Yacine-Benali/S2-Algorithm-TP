#include <stdlib.h>
#include <stdio.h>

typedef struct produit
{
    int code;
    char nom[20];
    int quantite;
    double prix;
} Produit;

void questionDeux()
{
    FILE *output = fopen("controle.dat", "wb");
    FILE *input = fopen("produit.dat", "rb");
    Produit produit;
    while (!feof(input))
    {
        fread(&produit, sizeof(Produit), 1, input);

        if (produit.quantite < 100)
            fwrite(&produit, sizeof(Produit), 1, output);
    }
    fclose(output);
    fclose(input);
}

void questionTrois()
{
    FILE *inputBinary = fopen("controle.dat", "rb");
    FILE *inputText = fopen("input.txt", "r");

    int compteur = 0;
    char nomTemp[50];
    Produit produit;

    if (!feof(inputText))
    {
        fscanf(inputText, "%s\t", nomTemp);

        while (fread(&produit, sizeof(Produit), 1, inputBinary) == 1)
        {
            if (strcmp(produit.nom, nomTemp) == 0)
            {
                compteur++;
            }
        }
    }
    fclose(inputBinary);
    fclose(inputText);
}
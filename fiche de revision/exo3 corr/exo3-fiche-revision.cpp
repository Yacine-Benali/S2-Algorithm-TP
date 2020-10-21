#include <stdio.h>
#include <string.h>
#define NBPRODUITS 10
typedef struct
{
	int code;
	char designation[20];
	int quantite;
	float prix;
} produit;

void RemplirControle(FILE *f);
int nbmots(FILE *f);

main()
{
	FILE *infile, *outfile;
	produit p[NBPRODUITS];
	int i;
	// R�ponse � la question 1
	outfile = fopen("produit.dat", "wb"); // Fichier binaire o� stocker les produits
	if (outfile != NULL)
	{
		for (i = 0; i < NBPRODUITS; i++)
		{
			printf("Entrer le code :");
			scanf("%d", &p[i].code);
			printf("Entrer la designation :");
			scanf("%s", p[i].designation);
			printf("Entrer la quantite :");
			scanf("%d", &p[i].quantite);
			printf("Entrer le prix : ");
			scanf("%f", &p[i].prix);
		}
		fwrite(p, sizeof(produit), NBPRODUITS, outfile); // Ecriture par blocs
		fclose(outfile);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier en ecriture\n");
		return 1;
	}
	// R�ponse � la question 2
	outfile = fopen("controle.dat", "w"); // Fichier texte en �criture
	if (outfile != NULL)
	{
		RemplirControle(outfile);
		fclose(outfile);
	}
	else
		return 2; // Ouverture impossible
	// R�ponse � la question 3
	infile = fopen("texte.txt", "r"); // Fichier texte contenant une liste de d�signations de produits
	if (infile != NULL)
	{
		printf("Nbre de mots (designations des produits) communs aux 2 fichiers = %d\n", nbmots(infile));
		fclose(infile);
	}
	else
		return 3; // Ouverture impossible
	printf("Fin de traitement, Merci et au revoir!\n");
}
void RemplirControle(FILE *f)
{
	FILE *infile;
	produit p[NBPRODUITS];
	int i, n;
	infile = fopen("produit.dat", "rb");
	if (infile != NULL)
	{
		if (!feof(infile))
			n = fread(p, sizeof(produit), NBPRODUITS, infile);
		for (i = 0; i < n; i++)
			if (p[i].quantite <= 100)
				fprintf(f, "%s\t", p[i].designation);
		fclose(infile);
	}
}
int nbmots(FILE *f)
{
	FILE *infile;
	char chaine1[20], chaine2[20];
	int k = 0;
	while (!feof(f))
	{
		fscanf(f, "%s\t", chaine1);
		infile = fopen("controle.dat", "r");
		if (infile != NULL)
		{
			while (!feof(infile))
			{
				fscanf(infile, "%s\t", chaine2);
				if (strcmp(chaine1, chaine2) == 0)
					k++;
			}
			fclose(infile);
		}
		else
			return 4; // Ouverture impossible
	}
	return k;
}

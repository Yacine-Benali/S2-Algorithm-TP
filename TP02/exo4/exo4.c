/* Programme à copier  et à exécuter pour faire exo4fiche2 */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct emp /* creation d'un type emp  */
{
    int num;
    int salaire;
    char nom[10];
    char prenom[10];
    int sex;
    char dep[20];
    int prof;
    int age;
} emp;

void creer_fichier(FILE *f, char n[])
{
    char choix;
    char choixSex;
    char choixProf;
    emp employer;
    system("cls");
    printf("CREATION DU FICHIER \n\n");
    printf("NOM DU FICHIER A CREER: ");
    scanf("%s", n);
    f = fopen(n, "w");
    do
    {
        printf("\nSAISIE DES INFORMATIONS D'UNE PERSONNE ?(o/n) ");
        scanf("\n%c", &choix);

        if ((choix == 'o') || (choix == 'O'))
        {
            printf("\n NUM: ");
            scanf("%d", &employer.num);
            printf("\n SALAIRE: ");
            scanf("%d", &employer.salaire);
            printf("\n NOM: ");
            scanf("%s", &employer.nom);
            printf("\n PRENOM: ");
            scanf("%s", &employer.prenom);

            printf("\n HOMME ?(o/n) : ");
            scanf("\n%c", &choixSex);
            if ((choixSex == 'o') || (choixSex == 'O'))
                employer.sex = 1;

            else
                employer.sex = 0;

            printf("\n DEPARTMENT: ");
            scanf("%s", &employer.dep);
            printf("\n ENSEIGNANT ?(o/n) : ");
            scanf("\n%c", &choixProf);
            if ((choixProf == 'o') || (choixProf == 'O'))
                employer.prof = 1;

            else
                employer.prof = 0;

            printf("\n AGE: ");
            scanf("%d", &employer.age);

            fwrite(&employer, sizeof(emp), 1, f);
        }
    } while ((choix == 'o') || (choix == 'O'));
    fclose(f);
}

void Affiche_fichier(FILE *f, char *n)
{
    emp employer;
    int c = 0;
    system("cls");
    printf("LECTURE DU FICHIER\n\n");
    printf("NOM DU FICHIER A LIRE: ");
    scanf("%s", n);
    f = fopen(n, "r");
    if (f == NULL)
        printf("\nERREUR, CE FICHIER N'EXISTE PAS\n\n");
    else
    {
        printf("\nLISTING DES INFORMATIONS  DES PERSONNES DU FICHIER \n\n");
        while (fread(&employer, sizeof(emp), 1, f) != 0)
        {
            printf("PERSONNE  DE NUMERO %d: \n", c);
            c++;
            printf("%s %s %d an(s)\n\n", employer.nom, employer.prenom, employer.age);
        }
        fclose(f);
    }
    printf("POUR CONTINUER FRAPPER UNE TOUCHE ");
    getch();
}

void recherche(FILE *f, char *n)
{
    emp employer;
    int compteur = 0;
    char boul = 0, nom[10], pnom[10];
    system("cls");
    printf("RECHERCHE DE PERSONNE\n\n");
    printf("NOM DU FICHIER: ");
    scanf("%s", n);
    f = fopen(n, "r");
    printf("\n IDENTITE A CHERCHER:\n");
    printf("\n NOM: ");
    scanf("%s", nom);
    printf("\n PRENOM: ");
    scanf("%s", pnom);
    while ((fread(&employer, sizeof(emp), 1, f) != 0) && (boul == 0))
    {
        if ((strcmp(employer.nom, nom) == 0) && (strcmp(employer.prenom, pnom) == 0))
        {
            boul = 1;
            printf("oui on le trouve sa position est %d \n", compteur);
        }
        compteur++;
    }
    if (boul == 0)
        printf("non trouvé \n");
    fclose(f);
    printf("POUR CONTINUER FRAPPER UNE TOUCHE ");
    getch();
}

int main()
{
    FILE *fichier;
    char nom[10]; /* nom du fichier */
    char choix;
    do
    {
        system("cls");
        printf("\t\t\tGESTION DE FICHIER\n");
        printf("\t\t\t------------------\n\n\n");
        printf("    CREATION DU FICHIER PERSONNE    --->  1\n");
        printf("    AAFICHER EMPLOYER NUM 6         --->  2\n");
        printf("    COMPTER NOMBRE DE FEMME         --->  3\n");
        printf("    SORTIE ET ARRET EXECUTION       --->  4\n\n");
        printf("       FAITES VOTRE CHOIX   ---> ");
        choix = (char)getchar();
        switch (choix)
        {
        case '1':
            creer_fichier(fichier, nom);
            break;
        case '2':
            Affiche_fichier(fichier, nom);
            break;
        case '3':
           
            break;
        }
    } while (choix != '4');
}

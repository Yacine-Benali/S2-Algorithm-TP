#include <stdio.h>

int main()
{

    FILE *fptr;
    fptr = fopen("essai1.dat", "w+");

    if(fptr == NULL)
    {
        printf("Erreur d'ouverture du fichier 1!\n");
        return -1;
    }
    fputs("hello world",fptr);
    rewind(fptr);
    char string[50];
    fgets(string,50,fptr);
    printf("read %s",string);
    FILE *fptr2;
    fptr2 = fopen("essai2.dat","w+");
    if(fptr2 == NULL)
    {
        printf("Erreur d'ouverture du fichier 2!\n");
        return -1;
    }
    

    fprintf(fptr2,"%s",string);
    fclose(fptr);
    fclose(fptr2);



}
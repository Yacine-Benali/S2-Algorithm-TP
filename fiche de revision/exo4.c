#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input = fopen("exo4.txt", "r");
    int nombreDeMots = 0;
    int nombreDeChar = 0;
    char lePlusLongue[50];
    char temp[50];
    double moyenne = 0;

    //initialiser le plus longue mot
    strcpy(lePlusLongue, "");
    while (!feof(input))
    {

        fscanf(input, "%s\n", temp);
        printf("nombre de char %d\n", strlen(temp));
        nombreDeMots++;
        nombreDeChar = nombreDeChar + strlen(temp);
        if (strlen(temp) > strlen(lePlusLongue))
        {
            strcpy(lePlusLongue, temp);
        }
    }

    moyenne = nombreDeChar / nombreDeMots;

    printf("nombre de mot %d\nle mot le plus long %s\nmoyenne: %f", nombreDeMots, lePlusLongue, moyenne);
}
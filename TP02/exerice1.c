#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int counter;
    FILE *fp = fopen("exercice1.txt", "r");

    counter = 0;
    ch = fgetc(fp);

    if(fp == NULL)
    {
        printf("could not open file");
        return -1;
    }

    // added this statement because a file can start
    // with a word that starts with the letter A
    if (ch == 'A')
        counter++;

    while (ch != EOF)
    {
        if (ch == ' ' && (ch = fgetc(fp) == 'A'))
        {
            counter++;
        }
        else
        {
            ch = fgetc(fp);
        }
    }
    fclose(fp);
    printf("\nnumber of words that starts with letter A are: %d", counter);
}
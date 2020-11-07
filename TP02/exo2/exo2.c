#include <stdio.h>

int main()
{
    FILE *fFile, *gFile;

    fFile = fopen("f", "r");
    if (fFile == NULL)
    {
        printf("could not open f file \n");
        return -1;
    }
    gFile = fopen("g", "w+");
    if (gFile == NULL)
    {
        printf("could not creat gfile ");
        return -2;
    }

    char first, second, temp;
    first = getc(fFile);
    second = first;

    while ((second = getc(fFile)) != EOF)
    {
        if (first != ' ')
        {
            fputc(first, gFile);
        }
        else if (first == ' ' && second != ' ')
        {
            fputc(first, gFile);
        }
        first = second;
    }
    fputc(first, gFile);
    fclose(fFile);
    fclose(gFile);
}
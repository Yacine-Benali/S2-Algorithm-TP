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
    gFile = fopen("g", "w");
    if (gFile == NULL)
    {
        printf("could not creat gfile ");
        return -2;
    }

    char first, second, temp;
    first = fgetc(fFile);
    fputc(first, gFile);
    while ((second = fgetc(fFile)) != EOF)
    {
        if (first == ' ' && second == ' ')
        {
            temp = fgetc(fFile);
            while (temp == ' ')
            { /* nothing but advancing the cursuer position*/
                temp = fgetc(fFile);
            }
            fputc(temp, gFile);
        }
        else
        {
            fputc(second, gFile);
        }
        first = second;
    }
    fclose(fFile);
    fclose(gFile);
}
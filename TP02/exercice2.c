#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int counter;
    FILE *ff = fopen("F.txt", "r");
    FILE *fg = fopen("G.txt", "w");

    if(ff == NULL || fg == NULL)
    {
        printf("could not open one of the files file");
        return -1;
    }
    while ((ch = fgetc(ff)) != EOF)
    {
        if (ch == ' ')
        {
            fputc(' ',fg);
            while ((ch = fgetc(ff)) == ' ')
            {

            }
            fputc(ch,fg);
        }
        fputc(ch,fg);
    }
}
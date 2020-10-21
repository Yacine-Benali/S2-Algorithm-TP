#include <stdio.h>

int main()
{
    FILE *fp = fopen("test", "wb");

    for (int i = 0; i < 10; i++)
    {
        fwrite(&i, sizeof(int), 1, fp);
    }
    fclose(fp);

    FILE *pf = fopen("test", "rb");
    int d;
    while (fread(&d, sizeof(int), 1, pf) == 1)
    {
        int i = ;
        printf("%d => %d \n", d, i);
    }
}
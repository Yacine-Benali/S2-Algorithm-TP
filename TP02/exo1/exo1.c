#include <stdio.h>


int main()
{
    FILE *fp = fopen("temp.txt","w+");

    fputs("aaA Aaa aA Aaa A AAA",fp);

    rewind(fp);

    char first,second;
    int comptuer = 0;

    second = fgetc(fp);
    if(second == 'A')
            comptuer++;
    first = second;
    while((second = fgetc(fp)) != EOF)
    {
        if(second == 'A' && first == ' ')
            comptuer++;

        first = second;
    }
    printf("le nombre de mot commençant par la lettre A %d",comptuer);
    
    
}
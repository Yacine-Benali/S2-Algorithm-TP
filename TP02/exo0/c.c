#include <stdio.h>

int main()
{
    FILE *bfile;
    bfile = fopen("bfile","w+b");

    if(bfile == NULL)
    {
        printf("errer de creation du fichier bfile");
        return -1;
    }

    int n;
    for(int i = 0 ; i< 10 ; i++)
    {
        printf("entrer entier num %d :",i);
        scanf("%d",&n);
        fwrite(&n,sizeof(n),1,bfile);
    }
    rewind(bfile);
    printf("vous avez entrer: \n");
    while(fread(&n,sizeof(int),1,bfile) == 1)
    {
        printf("%d  ",n);
    }
    

}
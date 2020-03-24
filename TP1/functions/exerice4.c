#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mirror(char str[])
{
    int t = strlen(str);
    int i = 0;
    char *temp;

    strcpy(temp,str);

    for(i = 0 ; i < t ; i++)
    {
        str[i] = temp[t-i-1];
    }

}

int main()
{
    char str[] = "hello";
    
    // printf("enter the sentence:");
    // scanf("%s",str);
    printf("orgignal string: %s \n",str);


    mirror(str);
    printf("mirrored string: %s",str);

}
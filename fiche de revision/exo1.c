#include <stdio.h>

void fonction(int n)
{

    int c, d;

    c = n / 10;
    d = n % 10;
    printf("%d", d);

    while (c != 0)
    {
        printf("%d", (c % 10));
        c = c / 10;
    }
}
int main()
{
    int chiffre;
    printf("entrer un chiffre: ");
    scanf("%d", &chiffre);

    fonction(chiffre);
}
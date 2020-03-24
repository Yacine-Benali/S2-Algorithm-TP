#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
    if (b == a)
    {
        return a;
    }
    if (b == 0)
    {
        return a;
    }
    else
    {
        pgcd(b, a % b);
    }
}

int main()
{
    int a;
    int b;
    int c;

    printf("enter the two numbers: ");
    scanf("%d %d",&a,&b);
    if (a > b)
    {
        c = pgcd(a, b);
    }
    else
    {
        c = pgcd(b, a);
    }

    printf("pgcd of %d and %d is %d", a, b, c);
}
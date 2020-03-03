#include <stdio.h>

int power(int x, int n)
{
    int result = 1;

    if (n == 0)
    {
        return result;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            result *= x;
        }
        return result;
    }
}

int main()
{
    
    int x, n;
    printf("enter a number:");
    scanf("%d", &x);

    printf("enter the power:");
    scanf("%d", &n);

    printf("%d ^ %d = %d", x, n, power(x, n));
}
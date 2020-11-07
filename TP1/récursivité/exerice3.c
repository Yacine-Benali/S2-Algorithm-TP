#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int counter, int f0, int f1)
{

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
        return 1;
    else if (n == counter)
    {
        return (f0 + f1);
    }
    else
    {
        counter++;
        fibonacci(n, counter, f1, (f0 + f1));
    }
}

int main()
{
    int n;
    printf("how many fibonacci number to show: ");
    scanf("%d", &n);

    int result = fibonacci(n, 2, 0, 1);
    printf("f%d is: %d", n, result);
}
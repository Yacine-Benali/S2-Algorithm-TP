/*
just learned about heap and stack let ruin some shit 

 C program to demonstrate heap overflow 
 by continuously allocating memory 

 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    for ( i = 0; i < 1000000; i++)
    {
        // Allocating memory without freeing it
        printf("allocation number %d \n", i);
        int *ptr = (int *)malloc(sizeof(int) * 1000);
    }
}
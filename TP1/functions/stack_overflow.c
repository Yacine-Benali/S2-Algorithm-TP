// C program to demonstrate stack overflow
// by creating a non-terminating recursive
// function.
#include <stdio.h>

void fun(int x)
{
    printf("hello world\n");
    fun(x);
}

int main()
{
    // first method
    // Creating a matrix of a big size
    // which may result in stack overflow.
    // doesnt work on modern systems
    //int mat[10000000][10000000000];
    

    // second method
    //recursive function that calls it self infinitly
    int x = 5;
    fun(x);
}
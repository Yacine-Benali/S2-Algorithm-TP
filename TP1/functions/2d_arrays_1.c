#include <stdio.h>
#define TAILLE 3

void print(int arr[TAILLE][TAILLE])
{
    int i, j;
    for (i = 0; i < TAILLE; i++)
        for (j = 0; j < TAILLE; j++)
            printf("%d ", arr[i][j]);
}

int main()
{
    int arr[TAILLE][TAILLE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    print(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define TAILLE 50

void deleteReplicated(int arr[], int *n)
{
    int i, p = 0;
    for (i = 0; i < *n; i++)
    {
        if (arr[i] != arr[p])
        {
            p++;
            arr[p] = arr[i];
        }
    }

    *n = ++p;
}

int main()
{

    int arr[TAILLE];
    int n, i;
    printf("enter the size of the array: ");
    scanf("%d", &n);

    // fill the array
    for (i = 0; i < n; i++)
    {
        printf("T[%d]:", i);
        scanf("%d", &arr[i]);
    }

    printf("array before deleting replicated numbers: \n");
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);

    deleteReplicated(arr, &n);
    printf("\narray after deleting replicated values \n");

    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
}
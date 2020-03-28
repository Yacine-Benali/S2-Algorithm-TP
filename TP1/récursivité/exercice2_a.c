#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int size, int value, int index)
{

    if (index == size)
    {
        return -1;
    }
    else if (arr[index] == value)
    {
        return index;
    }
    else
    {
        index++;
        search(arr, size, value, index);
    }
}

int main()
{

    int size, i, value;
    
    printf("enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    // fill the array
    for (i = 0; i < size; i++)
    {
        printf("T[%d]:", i);
        scanf("%d", &arr[i]);
    }

    printf("enter the value to search for: ");
    scanf("%d", &value);

    int index = search(arr, size, value, 0);

    if (index == -1)
    {
        printf("value not found");
    }
    else
    {
        printf("value found, it index is: %d", index);
    }
}
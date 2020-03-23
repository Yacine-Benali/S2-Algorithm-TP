#include <stdio.h>
#include <stdlib.h>

int columnSum(int *matrix, int size, int columnNumber)
{
    int i;
    int sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += *(matrix + i * size + columnNumber);
    }

    return sum;
}

void swap(int *matrix, int size, int c1, int c2)
{
    int i;
    int temp;
    for (i = 0; i < size; i++)
    {
        temp = *(matrix + i * size + c1);
        *(matrix + i * size + c1) = *(matrix + i * size + c2);
        *(matrix + i * size + c2) = temp;
    }
}

int main()
{
    int size, i, j;
    printf("enter the size of the matrix: ");
    scanf("%d", &size);

    int matrix[size][size];
    int eachColumnSum[size];

    // input
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("matrixe[%d][%d]:", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    // ouput matrix before operations
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // calculating each row sum
    for (i = 0; i < size; i++)
    {
        eachColumnSum[i] = columnSum(*matrix, size, i);
    }

    int min, max, c1, c2;
    min = max = eachColumnSum[0];
    c1 = c2 = 0;

    // finding mix and min
    for (i = 0; i < size; i++)
    {

        if (eachColumnSum[i] > max)
        {
            max = eachColumnSum[i];
            c1 = i;
        }
        else if (eachColumnSum[i] < min)
        {
            min = eachColumnSum[i];
            c2 = i;
        }
    }

    printf("%d is max and %d is min \n", c1, c2);
    printf("swaping between %d and %d...\n", c1, c2);
    swap(*matrix, size, c1, c2);
    
    // ouput after swaping min and max
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}
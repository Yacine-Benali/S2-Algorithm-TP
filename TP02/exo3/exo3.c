#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input1, *input2, *output;

    input1 = fopen("input1", "r");
    input2 = fopen("input2", "r");
    output = fopen("output", "w");

    int input1Int, input2Int;

    int f1 = 1;
    int f2 = 1;

    while (feof(input1) == 0 || feof(input2) == 0)
    {
        if (f1 && feof(input1) == 0)
            fscanf(input1, "%d", &input1Int);
        if (f2 && feof(input2) == 0)
            fscanf(input2, "%d", &input2Int);

        printf("%d vs %d \n", input1Int, input2Int);
        if (input1Int < input2Int)
        {
            fprintf(output, "%d ", input1Int);
            f1 = 1;
            f2 = 0;
        }
        else
        {
            fprintf(output, "%d ", input2Int);
            f2 = 1;
            f1 = 0;
        }
    }

    int lastInputChecked = 0;
    while (feof(input2) == 0)
    {
        fscanf(input2, "%d", &input2Int);
        if (input1Int < input2Int && !lastInputChecked)
        {
            printf("*%d vs %d \n", input1Int, input2Int);
            fprintf(output, "%d ", input1Int);
            lastInputChecked = 1;
        }

        fprintf(output, "%d ", input2Int);
    }

    lastInputChecked = 0;
    while (feof(input1) == 0)
    {
        fscanf(input1, "%d", &input1Int);
        if (input2Int < input1Int && !lastInputChecked)
        {
            printf("**%d vs %d \n", input1Int, input2Int);
            fprintf(output, "%d ", input2Int);
            lastInputChecked = 1;
        }

        fprintf(output, "%d ", input1Int);
    }

    fclose(input1);
    fclose(input2);
    fclose(output);
}

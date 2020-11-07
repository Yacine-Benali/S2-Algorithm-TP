#include <stdio.h>
void print(int m, int n, int arr[m][n] )
{
  int i, j;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      printf("%d ", arr[i][j]);
}

int main()
{
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int m = 3, n = 3;

  // We can also use "print(&arr[0][0], m, n);"
  print(m, n,arr);
  return 0;
}
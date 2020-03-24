#include <stdio.h> 

// passing 2d array to a function in C with pointers
void print(int *arr, int m, int n) 
{ 
	int i, j; 
	for (i = 0; i < m; i++) 
	for (j = 0; j < n; j++) 
		printf("%d ", *(arr+i*n + j)); 
} 

int main() 
{ 
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
	int m = 3, n = 3; 

	// We can also use "print(&arr[0][0], m, n);"
	printf("%d \n",arr);  
	printf("%d \n",arr + 1);  
	printf("%d \n",*arr + 1); 
	printf("%d \n",**arr); 
	return 0; 
} 
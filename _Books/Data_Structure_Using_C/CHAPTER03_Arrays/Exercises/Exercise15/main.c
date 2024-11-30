#include <stdio.h>

#define SIZE 3

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int sum = 0;

	// Data Initialization
	// Read matrix
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("mat[%d][%d] = ", i, j);
			scanf_s("%d", &mat[i][j]);
		}
	}

	// Implementation
	for (int i = 0; i < SIZE; i++)
	{
		sum += mat[i][i];
	}

	// Display the result
	printf("The origin matrix:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}

	printf("The sum of the matrix's diagonal elements: %d\n", sum);
	return 0;
}
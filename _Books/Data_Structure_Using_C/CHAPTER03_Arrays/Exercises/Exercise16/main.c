#include <stdio.h>

#define SIZE 3

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int sum = 0;

	// Data Initialization
	printf("The size of the matrix: %d * %d\n", SIZE, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("mat[%d][%d] = ", i, j);
			scanf_s("%d", &mat[i][j]);
		}
	}

	// Implementation
	for (int i = 0; i < SIZE - 1; i++)
	{
		sum += mat[i][i + 1];
	}

	// Display the result
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}

	printf("The sum of the elements above the main diagonal: %d\n", sum);
	return 0;
}
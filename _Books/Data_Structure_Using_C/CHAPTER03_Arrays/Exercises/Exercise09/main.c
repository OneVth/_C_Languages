#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int product = 1;

	// Data Initialization
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat[i][j] = rand() % 10 + 1;
		}
	}

	// Implementation
	for (int i = 0; i < SIZE - 1; i++)
	{
		product *= mat[i][i + 1];
	}

	// Display the result
	printf("mat-------------\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", mat[i][j]);
		}
		putchar('\n');
	}
	printf("----------------\n");
	printf("Product of the elements stored on the diagonal above the main diagonal: %d\n", product);
	return 0;
}
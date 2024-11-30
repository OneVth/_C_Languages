#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int (*ptr)[SIZE] = mat;
	int sum = 0;

	srand((unsigned)time(NULL));

	// Data initialization
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat[i][j] = rand() % 10;
		}
	}

	// Implementation
	for (int i = 0; i < SIZE; i++)
	{
		sum += ptr[i][i];
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
	putchar('\n');

	printf("The sum of the elements that are stored on the main diagonal of matrix: %d\n",
		sum);
	return 0;
}
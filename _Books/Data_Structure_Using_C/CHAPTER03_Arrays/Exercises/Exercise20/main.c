#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int isSymmetric(int (*)[SIZE], int);

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int cnt = 0;

	// Data Initialization
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			mat[i][j] = mat[j][i] = rand() % 10;
		}
	}

	// Display the result
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", mat[i][j]);
		}
		putchar('\n');
	}
	printf("The result of the isSymmetric(): %d\n", isSymmetric(mat, SIZE));
	return 0;
}

int isSymmetric(const int (*a)[SIZE], const int n)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (a[i][j] != a[j][i])
				return 0;
		}
	}
	return 1;
}
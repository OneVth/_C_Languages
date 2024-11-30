#include <stdio.h>

#define SIZE 5

int isUpperTriangular(int (*)[SIZE], int);

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };

	// Data Initialization
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i < j)
				mat[i][j] = 1;
		}
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

	printf("The result of isUpperTriangular: %d\n", isUpperTriangular(mat, SIZE));
	return 0;
}

int isUpperTriangular(int (*a)[SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i > j)
			{
				if (a[i][j] != 0)
					return 0;
			}
		}
	}
	return 1;
}
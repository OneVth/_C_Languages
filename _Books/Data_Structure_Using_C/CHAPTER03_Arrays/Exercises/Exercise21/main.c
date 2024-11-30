#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void)
{
	int A[SIZE][SIZE] = { 0 }, B[SIZE][SIZE] = { 0 }, mat[SIZE][SIZE] = { 0 };
	int X = 2, Y = 3;

	// Data Initialization
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			A[i][j] = rand() % 5 + 1;
			B[i][j] = rand() % 5 + 1;
		}
	}

	// Implementation
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat[i][j] = X * A[i][j] + Y * B[i][j];
		}
	}

	// Display the result
	printf("Matrix A:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", A[i][j]);
		}
		putchar('\n');
	}

	printf("\nMatrix B:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", B[i][j]);
		}
		putchar('\n');
	}

	printf("\nThe result of XA + YB:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", mat[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
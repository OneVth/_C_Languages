#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int cnt = 0;

	// Data Initialization
	srand((unsigned)time(NULL));

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
		for (int j = 0; j < SIZE; j++)
		{
			if (mat[i][j] != 0)
				cnt++;
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
	putchar('\n');

	printf("Count of the non-zero elements: %d\n", cnt);
	return 0;
}
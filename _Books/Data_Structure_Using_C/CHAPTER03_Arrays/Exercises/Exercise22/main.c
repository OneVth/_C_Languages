#include <stdio.h>

#define SIZE 5

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	const int (*ptr)[SIZE] = mat;

	// Data Initialization
	int cnt = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat[i][j] = cnt;
			cnt++;
		}
	}

	// Display the result
	printf("Matrix:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", ptr[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
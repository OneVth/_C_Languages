#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int mat1[3][3] = { 0 }, mat2[3][3] = { 0 }, mat_sum[3][3] = { 0 };

	int (*ptr1)[3] = mat1;
	int (*ptr2)[3] = mat2;

	srand((unsigned)time(NULL));

	// Data Initialization
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat1[i][j] = rand() % 10;
			mat2[i][j] = rand() % 10;
		}
	}

	// Implementation
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat_sum[i][j] = ptr1[i][j] + ptr2[i][j];
		}
	}

	// Display the result
	printf("mat1:---\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%2d ", mat1[i][j]);
		}
		putchar('\n');
	}
	printf("---------\n");

	printf("mat2:---\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%2d ", mat2[i][j]);
		}
		putchar('\n');
	}
	printf("---------\n");

	printf("mat_sum:\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%2d ", mat_sum[i][j]);
		}
		putchar('\n');
	}
	printf("---------\n");
	return 0;
}
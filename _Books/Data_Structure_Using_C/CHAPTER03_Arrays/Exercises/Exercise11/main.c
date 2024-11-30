#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void)
{
	int mat[SIZE][SIZE] = { 0 };
	int* arr_even = NULL, * arr_odd = NULL;
	int num_even = 0, num_odd = 0;

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
	// Calculate numbers of even and odd
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (mat[i][j] % 2 == 0)
			{
				num_even++;
			}
			else
			{
				num_odd++;
			}
		}
	}

	// allocate memoey base on numbers of even and odd
	arr_even = (int*)malloc(num_even * sizeof(int));
	arr_odd = (int*)malloc(num_odd * sizeof(int));

	if (arr_even == NULL || arr_odd == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	// insert numbers to arrays
	int idx_even = 0;
	int idx_odd = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (mat[i][j] % 2 == 0)
			{
				arr_even[idx_even] = mat[i][j];
				idx_even++;
			}
			else
			{
				arr_odd[idx_odd] = mat[i][j];
				idx_odd++;
			}
		}
	}

	// Display the result
	printf("Matrix:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}

	printf("\nEven numbers in the matrix:\n");
	for (int i = 0; i < num_even; i++)
	{
		printf("%d ", arr_even[i]);
	}

	printf("\nOdd numbers in the matrix:\n");
	for (int i = 0; i < num_odd; i++)
	{
		printf("%d ", arr_odd[i]);
	}

	// free allocated memory
	free(arr_even);
	free(arr_odd);
	return 0;
}
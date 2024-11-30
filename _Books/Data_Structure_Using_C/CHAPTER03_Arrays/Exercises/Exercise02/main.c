// The programs for storing pairs and print them where the sum is TARGET_SUM

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define TARGET_SUM 50

int main(void)
{
	int arr[MAX_NUMBER] = { 0 };
	int** pair = NULL;

	// Data Initialization-------------------------------------
	srand((unsigned)time(NULL));

	for (int i = 0; i < MAX_NUMBER; i++)
	{
		arr[i] = rand() % (TARGET_SUM + 1);
	}

	// Implementation-------------------------------------------

	// Calculating the number of pairs
	int num_pair = 0;
	for (int i = 0; i < MAX_NUMBER - 1; i++)
	{
		for (int j = i + 1; j < MAX_NUMBER; j++)
		{
			if (50 == arr[i] + arr[j])
			{
				num_pair++;
			}
		}
	}

	// Allocate memory to store the pairs
	// Each pair will store the indices of two elements that sum of TARGET_SUM
	pair = (int**)malloc(num_pair * sizeof(int*));
	for (int i = 0; i < num_pair; i++)
	{
		pair[i] = (int*)malloc(2 * sizeof(int));
	}

	// Get pair
	int pair_index = 0; // used as an index to store each found pair
	for (int i = 0; i < MAX_NUMBER - 1; i++)
	{
		for (int j = i + 1; j < MAX_NUMBER; j++)
		{
			if (50 == arr[i] + arr[j])
			{
				pair[pair_index][0] = i;
				pair[pair_index][1] = j;
				pair_index++;
			}
		}
	}

	// Display the result------------------------------------------------

	// Print whole elements
	if (num_pair == 0)
	{
		printf("No pairs found.\n");
		return 0;
	}

	printf("Matrix of whole numbers--------------\n");
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		if (i > 0 && 0 == i % 10)
			putchar('\n'); // just for new line

		printf("%2d ", arr[i]);
	}
	putchar('\n');
	printf("-------------------------------------\n\n");

	// Print pairs
	putchar('\n');
	printf("The number of pairs: %d---------------------\n", num_pair);
	for (int i = 0; i < num_pair; i++)
	{
		printf("The sum of arr[%d] = %2d and arr[%d] = %2d: %d\n",
			pair[i][0], arr[pair[i][0]],
			pair[i][1], arr[pair[i][1]],
			arr[pair[i][0]] + arr[pair[i][1]]);
	}
	printf("--------------------------------------------\n\n");

	// free allocated memory
	for (int i = 0; i < num_pair; i++)
	{
		free(pair[i]);
	}
	free(pair);
	return 0;
}
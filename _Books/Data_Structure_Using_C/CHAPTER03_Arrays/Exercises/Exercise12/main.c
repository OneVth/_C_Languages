#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void)
{
	double arr1[SIZE] = { 0 }, arr2[SIZE] = { 0 }, arr_merged[SIZE * 2] = { 0 };

	// Data Initialization
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		arr1[i] = rand() % 10 + rand() % 10 * 0.1;
		arr2[i] = rand() % 10 + rand() % 10 * 0.1;
	}

	// Implementation
	int idx = 0;
	for (int i = 0; i < SIZE; i++)
	{
		arr_merged[idx] = arr1[i];
		idx++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		arr_merged[idx] = arr2[i];
		idx++;
	}

	// Display the result
	printf("arr1:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%.1f ", arr1[i]);
	}
	putchar('\n');

	printf("\narr2:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	putchar('\n');

	printf("\narr_merged by reverse order:\n");
	for (int i = SIZE * 2 - 1; i >= 0; i--)
	{
		printf("%.1f ", arr_merged[i]);
	}
	putchar('\n');
	return 0;
}
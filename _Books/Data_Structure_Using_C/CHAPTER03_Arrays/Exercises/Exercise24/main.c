#include <stdio.h>

#define SIZE 5
#define MAX_NUMBER 10

int main(void)
{
	int arr[SIZE] = { 0 }, arr_deleted[SIZE] = { 0 };

	// Input from the user
	printf("Enter %d numbers:\n", SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("arr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}

	// Implementation
	// delete duplicate
	int freq[MAX_NUMBER] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		freq[arr[i]]++;
	}

	int idx = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (freq[arr[i]] == 1)
		{
			arr_deleted[idx] = arr[i];
			idx++;
		}
	}

	// Display the result
	printf("\nOrigin array:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("\nProcessed array:\n");
	for (int i = 0; i < idx; i++)
	{
		printf("arr[%d] = %d\n", i, arr_deleted[i]);
	}
	return 0;
}
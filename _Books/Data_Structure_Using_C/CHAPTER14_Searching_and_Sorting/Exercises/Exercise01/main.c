#include <stdio.h>

#define size 10

int main(void)
{
	int arr[size] = { 7, 1, 4, 12, 67, 33, 45 };
	int n = 7, swapCount = 0;

	// Print array before sorting
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	// Implementation
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				swapCount++;
			}
		}
	}

	// Print array after sorting
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("Swap Count: %d\n", swapCount);
	return 0;
}
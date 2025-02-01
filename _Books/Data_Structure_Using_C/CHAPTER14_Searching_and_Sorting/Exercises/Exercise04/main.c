#include <stdio.h>

#define size 10

int main(void)
{
	int arr[size] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = 7;

	// Print array before sorting
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	// Implementation
	for (int i = 0; i < n; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			int temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
	}

	// Print array after sorting
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	return 0;
}
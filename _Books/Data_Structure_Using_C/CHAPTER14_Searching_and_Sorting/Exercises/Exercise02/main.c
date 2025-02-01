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
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// Print array after sorting
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
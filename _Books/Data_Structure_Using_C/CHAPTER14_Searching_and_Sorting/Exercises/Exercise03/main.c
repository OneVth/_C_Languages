#include <stdio.h>

#define size 10

int main(void)
{
	int arr[size] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = 7;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}
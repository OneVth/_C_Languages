#include <stdio.h>

#define size 10

int partition(int[], const int, const int);
void quick_sort(int[], const int, const int);

int main(void)
{
	int arr[size] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = 7;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	return 0;
}

int partition(int arr[], const int low, const int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	i++;
	int temp = arr[high];
	arr[high] = arr[i];
	arr[i] = temp;
	return i;
}

void quick_sort(int arr[], const int low, const int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
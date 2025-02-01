#include <stdio.h>
#include <stdlib.h>

#define size 10

void insertion_sort(int[], int);
void selection_sort(int[], int);
void bubble_sort(int[], int);
void merge_sort(int[], int, int);
void quick_sort(int[], int, int);
void radix_sort(int[], int);
void shell_sort(int[], int);

int main(void)
{
	int arr[size] = { 12, 68, 34, 22, 54, 2, 3 };
	int n = 7;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	shell_sort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}

void insertion_sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void selection_sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			int temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
	}
}

void bubble_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;	// Size of the left sub-array
	int n2 = right - mid;		// Size of the right sub-array

	// Temporary arrays to hold the sub-arrays
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];

	for (int i = 0; i < n2; i++)
		R[i] = arr[mid + 1 + i];

	// Merge the temporary arrays back into arr[]
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy any remaining elements of L[]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy any remaining elements of R[]
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

void merge_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;	// Find the middle point

		// Recursively sort the left and right halves
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

int partition(int arr[], const int low, const int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high; j++)
	{
		if (arr[j] > pivot)
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

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int get_max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < max)
			max = arr[i];
	}
	return max;
}

// Function to perform counting sort based on a specific digit
void counting_sort(int arr[], int n, int exp)
{
	int* output = (int*)malloc(n * sizeof(int));
	int count[10] = { 0 };	// Count array to store occurrences of digits

	// Store the count of occurrences of each digit
	for (int i = 0; i < n; i++)
	{
		int digit = (arr[i] / exp) % 10;
		count[digit]++;
	}

	// Update count[i] to store the actual position of digits in ouput[]
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (int i = n - 1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	// Copy the output array back to arr[]
	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	free(output);
}

void radix_sort(int arr[], int n)
{
	// Find the maximum number to determine the number of digits
	int max = get_max(arr, n);

	// Perform counting sort for each digit
	// exp is the digit place (1, 10, 100, etc.)
	for (int exp = 1; max / exp > 0; exp *= 10)
		counting_sort(arr, n, exp);
}

void shell_sort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}
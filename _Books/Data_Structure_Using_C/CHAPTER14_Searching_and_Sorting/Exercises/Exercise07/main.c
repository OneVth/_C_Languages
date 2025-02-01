#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int get_max(int[], int);
void counting_sort(int[], int, int);
void radix_sort(int[], int);

int main(void)
{
	int arr[MAX] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = 8;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	radix_sort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}

int get_max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

// Function to perform counting sort based on a specific digit
void counting_sort(int arr[], int n, int exp)
{
	int* output = (int*)malloc(n* sizeof(int));	
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
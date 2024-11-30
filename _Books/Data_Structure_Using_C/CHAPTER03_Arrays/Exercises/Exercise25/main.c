#include <stdio.h>

#define MAX_SIZE 10

int main(void)
{
	double arr[MAX_SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double num = 11.11;
	int pos = 1, size = 5;

	// Display the array before the insertion
	printf("The origin array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", arr[i]);
	}

	if (pos > size + 1 || pos <= 0)
	{
		printf("\nERROR: The size of the current array is %d.\nPlease enter between 0 ~ %d\n.", size, size + 1);
		return 0;
	}

	// Implement
	for (int i = size - 1; i >= pos - 1; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos - 1] = num;
	size++;

	// Display the array after the insertion
	printf("\nThe processed array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", arr[i]);
	}
	return 0;
}
#include <stdio.h>
#include <math.h>

#define LENGTH 5

int main(void)
{
	int arr[LENGTH] = { 1, 2, 3, 4, 5 };
	int sum = 0;

	// Implementation
	// Calculate the sum of squares of the elements
	for (int i = 0; i < LENGTH; i++)
	{
		sum += (int)pow(arr[i], 2);
	}

	// Display the result
	for (int i = 0; i < LENGTH; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("\nSum of squares of the elements: %d\n", sum);
	return 0;
}
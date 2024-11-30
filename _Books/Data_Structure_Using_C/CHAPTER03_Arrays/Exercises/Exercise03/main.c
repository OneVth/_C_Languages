#include <stdio.h>

#define LENGTH 5

int main(void)
{
	int arr[LENGTH] = { 1, 2, 3, 4, 5 };

	// Implementation
	// Swapping second element with second-last element
	int temp = arr[1];
	arr[1] = arr[LENGTH - 2];
	arr[LENGTH - 2] = temp;

	// Display the result
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
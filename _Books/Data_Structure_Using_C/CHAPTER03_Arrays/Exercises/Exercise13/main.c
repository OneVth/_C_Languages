#include <stdio.h>

#define SIZE 5	

int main(void)
{
	int arr[SIZE] = { 1, 2, 3, 4, 5 }, changedArr[SIZE] = { 0 };
	int firstBig = 0, firstSmall = 0;
	int secondBig = 0, secondSmall = 0, idx_secondBig = 0, idx_secondSmall = 0;
	const int* pArr = arr; // Decalre pointer as constant to display origin array
	int* pChangedArr = changedArr;

	// Implementation-----------------------------------------------------------
	firstBig = arr[0];
	firstSmall = arr[0];

	// Find first big, small value
	for (int i = 1; i < SIZE; i++)
	{
		if (firstBig < pArr[i])
			firstBig = pArr[i];

		if (firstSmall > pArr[i])
			firstSmall = pArr[i];
	}

	// Find second big, small value with their index
	secondBig = firstSmall;
	secondSmall = firstBig;
	for (int i = 0; i < SIZE; i++)
	{
		if (secondBig < pArr[i] && firstBig != pArr[i])
		{
			secondBig = pArr[i];
			idx_secondBig = i;
		}

		if (secondSmall > pArr[i] && firstSmall != pArr[i])
		{
			secondSmall = pArr[i];
			idx_secondSmall = i;
		}
	}

	// Copy the origin array
	for (int i = 0; i < SIZE; i++)
	{
		pChangedArr[i] = pArr[i];
	}

	// interchange the second biggest and the second smallest number
	pChangedArr[idx_secondBig] = pArr[idx_secondSmall];
	pChangedArr[idx_secondSmall] = pArr[idx_secondBig];

	// Dispaly the result-------------------------------------------------------
	printf("The origin array:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\nChanged array:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", changedArr[i]);
	}
	return 0;
}
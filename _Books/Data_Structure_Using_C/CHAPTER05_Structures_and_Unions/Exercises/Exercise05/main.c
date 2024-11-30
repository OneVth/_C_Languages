#include <stdio.h>
#include <limits.h>

typedef struct smallest {
	int smallest1;
	int smallest2;
	int smallest3;
} SMALLEST;

int main(void)
{
	int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SMALLEST smalls = { INT_MAX, INT_MAX, INT_MAX };

	// Implementation
	for (int i = 0; i < 10; i++)
	{
		if (smalls.smallest1 > numbers[i])
		{
			smalls.smallest3 = smalls.smallest2;
			smalls.smallest2 = smalls.smallest1;
			smalls.smallest1 = numbers[i];
		}
		else if (smalls.smallest2 > numbers[i])
		{
			smalls.smallest3 = smalls.smallest2;
			smalls.smallest2 = numbers[i];
		}
		else if (smalls.smallest3 > numbers[i])
			smalls.smallest3 = numbers[i];
	}

	// Display the result
	printf("The smallest of three numbers are: %d %d %d\n",
		smalls.smallest1, smalls.smallest2, smalls.smallest3);
	return 0;
}
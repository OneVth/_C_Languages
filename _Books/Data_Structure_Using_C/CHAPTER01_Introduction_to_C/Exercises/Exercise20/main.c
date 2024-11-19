#include <stdio.h>

int main(void)
{
	int n = 0, sum = 0;
	double avg = 0.0;

	// Get a integer from user
	printf("Enter a number: ");
	scanf_s("%d", &n);

	// Calculate a sum 1 to n
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}

	// Calculate an average 1 to n
	avg = (double)sum / n;

	// Display the results
	printf("SUM: %d\n", sum);
	printf("AVERAGE: %.2f\n", avg);
	return 0;
}
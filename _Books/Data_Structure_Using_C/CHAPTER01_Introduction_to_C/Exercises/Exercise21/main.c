#include <stdio.h>

int main(void)
{
	int m = 0, n = 0;

	// Get m and n from user
	printf("Enter the m: ");
	scanf_s("%d", &m);

	printf("Enter the n: ");
	scanf_s("%d", &n);

	// Start from the first odd number greater than or equal to m
	if (m % 2 == 0)
		m++; // If m is even, increment it to the next odd number

	// Print odd numbers from m to n
	for (int i = m; i <= n; i += 2)
	{
		printf("%d ", i);
	}
	return 0;
}
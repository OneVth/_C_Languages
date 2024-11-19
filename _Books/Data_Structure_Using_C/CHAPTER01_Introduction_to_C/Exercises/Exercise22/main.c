#include <stdio.h>
#include <math.h>

int main(void)
{
	int m = 0, n = 45;

	// Get input from user
	printf("Enter a number m: ");
	scanf_s("%d", &m);

	printf("Enter a number n: ");
	scanf_s("%d", &n);

	if (m < 2)
		m = 2; // Prime numbers start from 2

	for (int i = m; i <= n; i++)
	{
		// Check whether i is prime or not 
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0; // i is not prime
				break;
			}
		}

		// print i if it's prime
		if (flag)
			printf("%d ", i);
	}

	putchar('\n');
	return 0;
}
#include <stdio.h>

int main(void)
{
	int num = 200, count = 0, sum = 0;

	for (int i = 1; i <= num; i++)
	{
		if ((i & 1) == 0)
		{
			count++;
			sum += i;
		}
	}

	printf("Count of even numbers between 1 ~ 200: %d\n", count);
	printf("Sum of the even numbers between 1 ~ 200: %d\n", sum);
	return 0;
}
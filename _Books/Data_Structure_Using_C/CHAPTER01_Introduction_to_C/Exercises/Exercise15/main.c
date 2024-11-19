#include <stdio.h>

int divisible(int);

int main(void)
{
	int input = 0;

	printf("Enter the number: ");
	scanf_s("%d", &input);

	if (divisible(input))
		printf("%d is divisible by 2\n", input);
	else
		printf("%d is not divisible by 2\n", input);
	return 0;
}

int divisible(int a)
{
	if (a % 2 == 0)
		return 1;

	return 0;
}
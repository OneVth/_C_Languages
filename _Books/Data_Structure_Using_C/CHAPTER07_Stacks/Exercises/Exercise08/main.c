#include <stdio.h>

int Lambda(const int);	// integer part of the logarithm base 2

int main(void)
{
	int n = 5;

	printf("Lambda(%d) = %d\n", n, Lambda(n));
	return 0;
}

int Lambda(const int n)
{
	if (n < 1)
		return -1;	// for error case

	if (n == 1)
		return 0;
	else
		return Lambda(n / 2) + 1;
}
#include <stdio.h>	

int getMin(int, int, int);

int main(void)
{
	int a = 15, b = 10, c = 30;
	int min = 0;

	min = getMin(a, b, c);

	// Display the values and the minimum
	printf("a: %d, b: %d, c: %d\n", a, b, c);
	printf("MIN: %d\n", min);
	return 0;
}

// Function to find the smallest of three integers
int getMin(int a, int b, int c)
{
	int min = a;

	if (min > b) min = b;
	if (min > c) min = c;
	return min;
}
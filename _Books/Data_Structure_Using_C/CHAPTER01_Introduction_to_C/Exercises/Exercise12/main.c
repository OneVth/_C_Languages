#include <stdio.h>

int main(void)
{
	double test = 1200000;

	printf("Exponential format (2 decimal places): %.2e\n", test);
	printf("Exponential format (2 decimal places): %.4e\n", test);
	printf("Exponential format (2 decimal places): %.8e\n", test);
	return 0;
}
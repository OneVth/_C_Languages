#include <stdio.h>

void CalculateSum(const double, const double, double*);

int main(void)
{
	double a = 12.345, b = 67.89, sum = 0.0;

	CalculateSum(a, b, &sum);

	printf("Sum of a: %.2f and b: %.2f = %.2f", a, b, sum);
	return 0;
}

void CalculateSum(const double a, const double b, double* sum)
{
	*sum = a + b;
}
#include <stdio.h>

int main(void)
{
	float a = 0.0f, b = 0.0f;
	int sum = 0;

	printf("Enter the first number: ");
	scanf_s("%f", &a);
	printf("Enter the second number: ");
	scanf_s("%f", &b);

	sum = (int)(a + b);
	printf("%.6f %.6f %d\n", a, b, sum);
	return 0;
}
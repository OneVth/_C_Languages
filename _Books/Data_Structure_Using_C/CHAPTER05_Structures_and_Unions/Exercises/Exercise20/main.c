#include <stdio.h>

typedef struct fraction {
	int numerator;
	int denominator;
} FRACTION;

int cmpfrac(const FRACTION*, const FRACTION*);

int main(void)
{
	FRACTION frac1 = { 0 };
	FRACTION frac2 = { 0 };

	// Get input from the user
	printf("Enter the first fraction's numerator: ");
	scanf_s("%d", &frac1.numerator);
	printf("Enter the first fraction's denominator: ");
	scanf_s("%d", &frac1.denominator);

	printf("Enter the first fraction's numerator: ");
	scanf_s("%d", &frac2.numerator);
	printf("Enter the first fraction's denominator: ");
	scanf_s("%d", &frac2.denominator);

	// Display the result
	int temp = cmpfrac(&frac1, &frac2);
	if (temp > 0)
		printf("fraction 1 is greater than fraction 2.\n");
	else if (temp == 0)
		printf("fraction 1 is equal to fraction 2.\n");
	else
		printf("fraction 1 is less than fraction 2.\n");
	return 0;
}

int cmpfrac(const FRACTION* left, const FRACTION* right)
{
	if (left->numerator * right->denominator < right->numerator * left->denominator)
		return -1;
	else if (left->numerator * right->denominator == right->numerator * left->denominator)
		return 0;
	else
		return 1;
}

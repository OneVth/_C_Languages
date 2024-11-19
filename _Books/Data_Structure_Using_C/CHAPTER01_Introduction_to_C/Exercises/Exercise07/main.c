#include <stdio.h>
#include <math.h>

int main(void)
{
	int amount = 0, years = 0;
	double rate = 0.0;
	double simpleInterest = 0.0, compoundInterest = 0.0;

	// Get input from the user
	printf("Enter the amount of cash: ");
	scanf_s("%d", &amount);

	printf("Enter the year: ");
	scanf_s("%d", &years);

	printf("Enter the rate of interest: ");
	scanf_s("%lf", &rate); // Use %lf for double with scanf_s

	// Calculate interests
	simpleInterest = amount * rate * years / 100;
	compoundInterest = amount * pow((1 + rate / 100), years) - amount;

	// Display the results
	printf("Amount: %d, Years: %d Rate: %.2f\n", amount, years, rate);
	printf("Simple Interest: %.2f\nCompound Interest: %.2f\n",
		simpleInterest, compoundInterest);
	return 0;
}